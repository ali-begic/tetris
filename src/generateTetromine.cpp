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

void MainWindow::generateTetromine() {
    if (nextTetromine == 0) {
        srand(time(0));
        int randomNumber = (rand() % 7) + 1;

        nextTetromine = randomNumber;
    }

    if (nextTetromine == 1) {
        currentTetromine = 1;
        positionOfTheTetromine = {194, 195, 196, 197};

        allowedMovementToTheLeft = 3;
        allowedMovementToTheRight = 3;

        colorOfTheTetromine = "lightblue";
    } else if (nextTetromine == 2) {
        currentTetromine = 2;
        positionOfTheTetromine = {184, 194, 195, 196};

        allowedMovementToTheLeft = 3;
        allowedMovementToTheRight = 4;

        colorOfTheTetromine = "blue";
    } else if (nextTetromine == 3) {
        currentTetromine = 3;
        positionOfTheTetromine = {186, 194, 195, 196};

        allowedMovementToTheLeft = 3;
        allowedMovementToTheRight = 4;

        colorOfTheTetromine = "orange";
    } else if (nextTetromine == 4) {
        currentTetromine = 4;
        positionOfTheTetromine = {185, 186, 195, 196};

        allowedMovementToTheLeft = 4;
        allowedMovementToTheRight = 4;

        colorOfTheTetromine = "yellow";
    } else if (nextTetromine == 5) {
        currentTetromine = 5;
        positionOfTheTetromine = {184, 185, 195, 196};

        allowedMovementToTheLeft = 3;
        allowedMovementToTheRight = 4;

        colorOfTheTetromine = "green";
    } else if (nextTetromine == 6) {
        currentTetromine = 6;
        positionOfTheTetromine = {185, 194, 195, 196};

        allowedMovementToTheLeft = 3;
        allowedMovementToTheRight = 4;

        colorOfTheTetromine = "purple";
    } else if (nextTetromine == 7) {
        currentTetromine = 7;
        positionOfTheTetromine = {185, 186, 194, 195};

        allowedMovementToTheLeft = 3;
        allowedMovementToTheRight = 4;

        colorOfTheTetromine = "red";
    }

    generateNextTetromine();
}

void MainWindow::generateNextTetromine() {
    srand(time(0));
    int randomNumber = (rand() % 7) + 1;

    nextTetromine = randomNumber;

    if (nextTetromine == 1) {
        ui->nextTetromineImage_frame->setStyleSheet("border-image: url(:/tetromines/tetromines/lightblue_tetromine.png)");
    } else if (nextTetromine == 2) {
        ui->nextTetromineImage_frame->setStyleSheet("border-image: url(:/tetromines/tetromines/blue_tetromine.png)");
    } else if (nextTetromine == 3) {
        ui->nextTetromineImage_frame->setStyleSheet("border-image: url(:/tetromines/tetromines/orange_tetromine.png)");
    } else if (nextTetromine == 4) {
        ui->nextTetromineImage_frame->setStyleSheet("border-image: url(:/tetromines/tetromines/yellow_tetromine.png)");
    } else if (nextTetromine == 5) {
        ui->nextTetromineImage_frame->setStyleSheet("border-image: url(:/tetromines/tetromines/green_tetromine.png)");
    } else if (nextTetromine == 6) {
        ui->nextTetromineImage_frame->setStyleSheet("border-image: url(:/tetromines/tetromines/purple_tetromine.png)");
    } else if (nextTetromine == 7) {
        ui->nextTetromineImage_frame->setStyleSheet("border-image: url(:/tetromines/tetromines/red_tetromine.png)");
    }
}
