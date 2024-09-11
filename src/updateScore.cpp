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

void MainWindow::updateScore(int points) {
    currentScore += points;
    pointsToAdd = 0;

    QFont tetrisFont("Retro Land Mayhem");

    ui->scoreInfo_label->setFont(tetrisFont);
    ui->scoreInfo_label->setText(QString("%1").arg(currentScore, 6, 10, QChar('0')));
    ui->scoreInfo_label->setAlignment(Qt::AlignCenter);
    ui->scoreInfo_label->setStyleSheet("color: white; font-size: 30px");

    if ((currentScore >= scoreForLevelUp) && speedValue > 100) {
        speedValue -= 100;
        speedOfTheTetromine = speedValue;
        scoreForLevelUp += 500;
    }
}
