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

void MainWindow::setStylesheets() {
    for (int i = 1; i <= 200; i++) {
        QString frameObjectName = QString("frame_%1").arg(i, 3, 10, QChar('0'));
        QFrame* frame = qobject_cast<QFrame*>(ui->centralwidget->findChild<QObject*>(frameObjectName));

        frame->setStyleSheet("background-color: black; border: none;");
    }

    for (int i = 0; i < 20; i++) {
        QList<int> section;

        for (int j = 1 + (i * 10); j <= 10 + (i * 10); j++) {
            section.append(j);
        }

        sections.append(section);
    }

    QFont tetrisFont("Retro Land Mayhem");

    ui->startNewGame_label->setFont(tetrisFont);
    ui->startNewGame_label->setText("<html><head/><body><p align='center'>PRESS ENTER TO</p><p align='center'>START THE GAME</p></body></html>");
    ui->startNewGame_label->setStyleSheet("color: white; font-size: 25px; background-color: none");

    ui->score_label->setFont(tetrisFont);
    ui->score_label->setText("SCORE");
    ui->score_label->setAlignment(Qt::AlignCenter);
    ui->score_label->setStyleSheet("color: white; font-size: 30px");

    ui->scoreInfo_label->setFont(tetrisFont);
    ui->scoreInfo_label->setText("000000");
    ui->scoreInfo_label->setAlignment(Qt::AlignCenter);
    ui->scoreInfo_label->setStyleSheet("color: white; font-size: 30px");

    ui->nextTetromine_label->setFont(tetrisFont);
    ui->nextTetromine_label->setText("NEXT");
    ui->nextTetromine_label->setAlignment(Qt::AlignCenter);
    ui->nextTetromine_label->setStyleSheet("color: white; font-size: 30px");

    ui->nextTetromine_frame->setStyleSheet("border: 2px solid gray");
    ui->nextTetromineImage_frame->setStyleSheet("border: none");

    ui->creator_label->setFont(tetrisFont);
    ui->creator_label->setText("<html><head/><body><p align='center'>ALITECH</p><p align='center'>WORKS</p></body></html>");
    ui->creator_label->setStyleSheet("color: white; font-size: 25px; background-color: none");

    ui->version_label->setFont(tetrisFont);
    ui->version_label->setText("<html><head/><p align='center'>v1.0</p></html>");
    ui->version_label->setStyleSheet("color: white; font-size: 25px; background-color: none");
}
