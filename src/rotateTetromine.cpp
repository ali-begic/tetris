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

void MainWindow::rotateTetromine() {
    std::sort(positionOfTheTetromine.begin(), positionOfTheTetromine.end());

    if (currentTetromine == 1) {
        if (numberOfRotations == 0) {
            if (positionOfTheTetromine[0] - 9 > 0 && !usedFrames.contains(positionOfTheTetromine[0] - 9)) {
                positionOfTheTetromine[0] -= 9;
            } else {
                return;
            }

            positionOfTheTetromine[2] += 9;
            positionOfTheTetromine[3] += 18;

            allowedMovementToTheLeft++;
            allowedMovementToTheRight += 2;

            numberOfRotations++;
        } else if (numberOfRotations == 1 && (allowedMovementToTheLeft >= 1 && allowedMovementToTheRight >= 2)) {
            positionOfTheTetromine[0] += 9;
            positionOfTheTetromine[2] -= 9;
            positionOfTheTetromine[3] -= 18;

            allowedMovementToTheLeft--;
            allowedMovementToTheRight -= 2;

            numberOfRotations = 0;
        }
    } else if (currentTetromine == 2) {
        if (numberOfRotations == 0) {
            positionOfTheTetromine[0] += 20;
            positionOfTheTetromine[1] += 11;
            positionOfTheTetromine[3] -= 11;

            allowedMovementToTheRight++;

            numberOfRotations++;
        } else if (numberOfRotations == 1 && (allowedMovementToTheLeft > 0 && allowedMovementToTheRight > 0)) {
            positionOfTheTetromine[0] += 9;
            positionOfTheTetromine[2] -= 8;
            positionOfTheTetromine[3] += 1;

            allowedMovementToTheRight--;

            numberOfRotations++;
        } else if (numberOfRotations == 2) {
            if (positionOfTheTetromine[0] - 9 > 0 && !usedFrames.contains(positionOfTheTetromine[0] - 9)) {
                positionOfTheTetromine[0] -= 9;
            } else {
                return;
            }

            positionOfTheTetromine[1] -= 9;
            positionOfTheTetromine[2] -= 1;
            positionOfTheTetromine[3] -= 1;

            allowedMovementToTheLeft++;

            numberOfRotations++;
        } else if (numberOfRotations == 3 && allowedMovementToTheLeft > 0) {
            positionOfTheTetromine[0] += 9;
            positionOfTheTetromine[1] -= 2;
            positionOfTheTetromine[3] -= 9;

            allowedMovementToTheLeft--;

            numberOfRotations = 0;
        }
    } else if (currentTetromine == 3) {
        if (numberOfRotations == 0) {
            positionOfTheTetromine[0] -= 2;
            positionOfTheTetromine[1] -= 9;
            positionOfTheTetromine[3] += 9;

            allowedMovementToTheRight++;

            numberOfRotations++;
        } else if (numberOfRotations == 1 && allowedMovementToTheRight > 0) {
            positionOfTheTetromine[0] += 10;
            positionOfTheTetromine[1] += 10;
            positionOfTheTetromine[2] += 1;
            positionOfTheTetromine[3] -= 1;

            allowedMovementToTheRight--;

            numberOfRotations++;
        } else if (numberOfRotations == 2) {
            if (positionOfTheTetromine[0] - 9 > 0 && !usedFrames.contains(positionOfTheTetromine[0] - 9)) {
                positionOfTheTetromine[0] -= 9;
            } else {
                return;
            }

            positionOfTheTetromine[2] += 9;
            positionOfTheTetromine[3] += 2;

            allowedMovementToTheLeft++;

            numberOfRotations++;
        } else if (numberOfRotations == 3 && (allowedMovementToTheLeft > 0 && allowedMovementToTheRight > 0)) {
            positionOfTheTetromine[0] += 1;
            positionOfTheTetromine[1] -= 1;
            positionOfTheTetromine[2] -= 10;
            positionOfTheTetromine[3] -= 10;

            allowedMovementToTheLeft--;

            numberOfRotations = 0;
        }
    } else if (currentTetromine == 5) {
        if (numberOfRotations == 0) {
            positionOfTheTetromine[0] += 1;
            positionOfTheTetromine[1] += 9;
            positionOfTheTetromine[3] += 8;

            allowedMovementToTheRight++;

            numberOfRotations++;
        } else if (numberOfRotations == 1) {
            positionOfTheTetromine[0] -= 1;
            positionOfTheTetromine[1] -= 9;
            positionOfTheTetromine[3] -= 8;

            allowedMovementToTheRight--;

            numberOfRotations = 0;
        }
    } else if (currentTetromine == 6) {
        if (numberOfRotations == 0) {
            positionOfTheTetromine[3] += 9;

            allowedMovementToTheRight++;

            numberOfRotations++;
        } else if (numberOfRotations == 1 && allowedMovementToTheRight > 0) {
            positionOfTheTetromine[0] += 9;
            positionOfTheTetromine[1] += 1;
            positionOfTheTetromine[2] += 1;

            allowedMovementToTheRight--;

            numberOfRotations++;
        } else if (numberOfRotations == 2) {
            if (positionOfTheTetromine[0] - 9 > 0 && !usedFrames.contains(positionOfTheTetromine[0] - 9)) {
                positionOfTheTetromine[0] -= 9;
            } else {
                return;
            }

            allowedMovementToTheLeft++;

            numberOfRotations++;
        } else if (numberOfRotations == 3 && allowedMovementToTheLeft > 0) {
            positionOfTheTetromine[1] -= 1;
            positionOfTheTetromine[2] -= 1;
            positionOfTheTetromine[3] -= 9;

            allowedMovementToTheLeft--;

            numberOfRotations = 0;
        }
    } else if (currentTetromine == 7) {
        if (numberOfRotations == 0) {
            positionOfTheTetromine[0] -= 1;
            positionOfTheTetromine[1] += 8;
            positionOfTheTetromine[2] += 1;
            positionOfTheTetromine[3] += 10;

            allowedMovementToTheRight++;

            numberOfRotations++;
        } else if (numberOfRotations == 1 && allowedMovementToTheRight > 0) {
            positionOfTheTetromine[0] += 1;
            positionOfTheTetromine[1] -= 8;
            positionOfTheTetromine[2] -= 1;
            positionOfTheTetromine[3] -= 10;

            allowedMovementToTheRight--;

            numberOfRotations = 0;
        }
    }
}
