/*
 * Copyright 2024 AliTech Works
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setStylesheets();

    connect(&mainTimer, &QTimer::timeout, this, [&]() {
        setNewObjectPosition();
        drawObject(true);
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::startGame() {
    setStylesheets();

    currentScore = 0;
    nextTetromine = 0;
    speedValue = 1000;
    speedOfTheTetromine = speedValue;

    usedFrames.clear();
    ui->startNewGame_label->clear();

    generateTetromine();
    drawObject(true);

    mainTimer.start(speedOfTheTetromine);
}

void MainWindow::setNewObjectPosition() {
    for (int i = 0; i < 4; i++) {
        if (usedFrames.contains(positionOfTheTetromine[i] - 10)) {
            speedOfTheTetromine = 0;
            continueWithExecuting = false;

            return;
        }
    }

    resetFrames(positionOfTheTetromine);

    for (int i = 0; i < 4; i++) {
        positionOfTheTetromine[i] -= 10;
    }
}

void MainWindow::drawObject(bool startTimer) {
    checkForFilledLines();

    if (speedOfTheTetromine == 35) {
        pointsToAdd++;
    }

    if (startTimer) {
        mainTimer.start(speedOfTheTetromine);
    }

    for (int i = 0; i < 4; i++) {
        if (positionOfTheTetromine[i] <= 200) {
            QString frameObjectName = QString("frame_%1").arg(positionOfTheTetromine[i], 3, 10, QChar('0'));
            QFrame *frame = qobject_cast<QFrame*>(ui->centralwidget->findChild<QObject*>(frameObjectName));

            frame->setStyleSheet("border-image: url(:/blocks/blocks/" + colorOfTheTetromine + "_block.png)");
        }
    }

    if ((sections[0].contains(positionOfTheTetromine[0]) || !continueWithExecuting) && startSecondTimer) {
        mainTimer.stop();

        QTimer::singleShot(speedOfTheTetromine, this, [=]{
            updateScore(pointsToAdd);

            for (int i = 0; i < 4; i++) {
                usedFrames.append(positionOfTheTetromine[i]);
            }

            numberOfRotations = 0;
            continueWithExecuting = true;
            startSecondTimer = true;

            generateTetromine();

            for (int i = 0; i < 4; i++) {
                if (usedFrames.contains(positionOfTheTetromine[i])) {
                    drawObject(false);

                    QFont tetrisFont("Retro Land Mayhem");

                    ui->startNewGame_label->setFont(tetrisFont);
                    ui->startNewGame_label->setText("<html><head/><body><p align='center'>GAME OVER</p></body></html>");
                    ui->startNewGame_label->setStyleSheet("color: white; font-size: 35px; background-color: black");

                    startNewGame = true;

                    return;
                }
            }

            speedOfTheTetromine = speedValue;
            drawObject(true);
        });

        startSecondTimer = false;
    }
}

void MainWindow::resetFrames(QList<int> &positions) {
    for (int i = 0; i < positions.size(); i++) {
        if (positions[i] <= 200) {
            QString frameObjectName = QString("frame_%1").arg(positions[i], 3, 10, QChar('0'));
            QFrame *frame = qobject_cast<QFrame*>(ui->centralwidget->findChild<QObject*>(frameObjectName));

            frame->setStyleSheet("background-color: black; border: none");
        }
    }
}

void MainWindow::checkForFilledLines() {
    QList<int> linesToRemove;

    for (int i = 0; i < 20; i++) {
        bool filledLine = true;

        for (int j = 0; j < 10; j++) {
            if (!usedFrames.contains(sections[i][j])) {
                filledLine = false;

                break;
            }
        }

        if (filledLine) {
            linesToRemove.append(i);
        }
    }

    for (int i = 0; i < linesToRemove.length(); i++) {
        if (linesToRemove.length() == 4) {
            pointsToAdd += 250;
        } else {
            pointsToAdd += 100;
        }

        updateScore(pointsToAdd);
        removeLine(linesToRemove[i]);
    }

    if (linesToRemove.length() != 0) {
        int distance = 0;

        for (int i = 0; i < 20; i++) {
            if (linesToRemove.contains(i)) {
                distance += 10;

                continue;
            } else {
                for (int j = 0; j < 10; j++) {
                    int indexOfElement;

                    if (usedFrames.contains(sections[i][j])) {
                        indexOfElement = usedFrames.indexOf(sections[i][j]);
                    } else {
                        continue;
                    }

                    QString styleSheetInformation;

                    QString originalFrameObjectName = QString("frame_%1").arg(usedFrames[indexOfElement], 3, 10, QChar('0'));
                    QFrame *originalFrame = qobject_cast<QFrame*>(ui->centralwidget->findChild<QObject*>(originalFrameObjectName));

                    styleSheetInformation = originalFrame->styleSheet();

                    originalFrame->setStyleSheet("background-color: black; border: none");

                    usedFrames[indexOfElement] -= distance;

                    QString newFrameObjectName = QString("frame_%1").arg(usedFrames[indexOfElement], 3, 10, QChar('0'));
                    QFrame *newFrame = qobject_cast<QFrame*>(ui->centralwidget->findChild<QObject*>(newFrameObjectName));

                    newFrame->setStyleSheet(styleSheetInformation);
                }
            }
        }
    }
}

void MainWindow::removeLine(int line) {
    for (int i = 0; i < 10; i++) {
        QString frameObjectName = QString("frame_%1").arg((i + 1) + (line  *10), 3, 10, QChar('0'));
        QFrame *frame = qobject_cast<QFrame*>(ui->centralwidget->findChild<QObject*>(frameObjectName));

        frame->setStyleSheet("background-color: black; border: none");

        usedFrames.removeOne((i + 1) + (line  *10));
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return && startNewGame) {
        startNewGame = false;

        startGame();
    }

    if (event->key() == Qt::Key_Left && !event->isAutoRepeat() && allowedMovementToTheLeft > 0 && !startNewGame) {
        for (int i = 0; i < 4; i++) {
            if (usedFrames.contains(positionOfTheTetromine[i] - 1)) {
                return;
            }
        }

        resetFrames(positionOfTheTetromine);

        allowedMovementToTheLeft--;
        allowedMovementToTheRight++;

        for (int i = 0; i < positionOfTheTetromine.size(); i++) {
            positionOfTheTetromine[i] -= 1;
        }

        drawObject(false);
    } else if (event->key() == Qt::Key_Right && !event->isAutoRepeat() && allowedMovementToTheRight > 0 && !startNewGame) {
        for (int i = 0; i < 4; i++) {
            if (usedFrames.contains(positionOfTheTetromine[i] + 1)) {
                return;
            }
        }

        resetFrames(positionOfTheTetromine);

        allowedMovementToTheLeft++;
        allowedMovementToTheRight--;

        for (int i = 0; i < positionOfTheTetromine.size(); i++) {
            positionOfTheTetromine[i] += 1;
        }

        drawObject(false);
    } else if (event->key() == Qt::Key_Up && !startNewGame) {
        resetFrames(positionOfTheTetromine);
        rotateTetromine();
        drawObject(false);
    } else if (event->key() == Qt::Key_Down && !event->isAutoRepeat() && !startNewGame) {
        if (!sections[0].contains(positionOfTheTetromine[0])) {
            speedOfTheTetromine = 35;

            setNewObjectPosition();
            drawObject(false);
            mainTimer.start(speedOfTheTetromine);
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Down && !event->isAutoRepeat() && !startNewGame) {
        if (speedOfTheTetromine != speedValue) {
            mainTimer.stop();
            pointsToAdd = 0;
            speedOfTheTetromine = speedValue;
            mainTimer.start(speedOfTheTetromine);
        }
    }
}
