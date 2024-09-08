# Tetris

**Tetris** is a highly polished and accurate replica of the original classic game, built with the Qt framework. This cross-platform application offers the familiar gameplay experience with smooth controls, a scoring system, and a next-piece preview window. Whether you're a seasoned Tetris player or new to the game, this version captures the essence of the timeless puzzle with precision.

## Features of the Tetris Qt Game

### Cross-Platform Compatibility
- Enjoy Tetris on multiple operating systems with seamless performance, thanks to the cross-platform nature of the Qt framework.

### Classic Gameplay
- **Accurate Mechanics**: Gameplay mirrors the original Tetris with smooth movement, piece rotation, and line clearing.
- **Scoring System**: Keep track of your score as you clear lines and level up.
- **Next Piece Preview**: A display shows the next piece, helping you strategize your moves.

### Sleek and Responsive UI
- Built with a modern, minimalistic design using the Qt framework, ensuring an intuitive user experience.

### Keyboard Controls
- Smooth and responsive keyboard controls for moving, rotating, and dropping pieces, ensuring an immersive gaming experience.

### Error Handling and Validation
- **Game Over Detection**: A proper end screen when the game is over, allowing players to restart or exit.
- **Input Validation**: Ensures smooth gameplay by preventing invalid actions or inputs.

These features make **Tetris** a fun and engaging experience for both new and experienced players.

## Building the Qt Application from Source

To build and run the **Tetris** application from source, follow these steps:

### 1. Clone the Repository
   - Ensure Git is installed on your system.
   - Open your terminal or command prompt, navigate to the desired directory, and run the following command:
     ```bash
     git clone https://github.com/ali-begic/tetris
     ```
   - Navigate to the cloned repository:
     ```bash
     cd tetris
     ```

### 2. Install Qt Dependencies
   - Ensure you have the necessary Qt libraries, compilers, and build tools installed. Follow platform-specific instructions:
     - [Qt Documentation for Windows](https://doc.qt.io/qt-6/windows-deployment.html)
     - [Qt Documentation for macOS](https://doc.qt.io/qt-6/macos-deployment.html)
     - [Qt Documentation for Linux](https://doc.qt.io/qt-6/linux-deployment.html)

### 3. Configure and Build the Application
   - Create a build directory and navigate into it:
     ```bash
     mkdir build
     cd build
     ```
   - Use `qmake` to generate the Makefile from the `.pro` file:
     ```bash
     qmake ../src/tetris.pro
     ```
   - Compile the application:
     - On Windows with MSVC:
       ```bash
       nmake
       ```
     - On Windows with MinGW:
       ```bash
       mingw32-make
       ```
     - On macOS and Linux:
       ```bash
       make
       ```

### 4. Run the Application
   - After building, the executable will be in the build directory. Run the game using:
     ```bash
     ./tetris
     ```

## Using `windeployqt` for Windows Deployment

To deploy the **Tetris** application on Windows, use `windeployqt` to gather all required dependencies.

### Steps:

1. **Build Your Application**:
   - Ensure it is fully built using the steps above.

2. **Open Command Prompt**:
   - Open "Developer Command Prompt for VS 2022" or "Qt MinGW" command prompt.

3. **Navigate to the Build Directory:**
   - Use the command prompt to navigate to the directory where your application’s executable is located:
     ```bash
     cd .../tetris/build/release
     ```

4. **Run `windeployqt`:**
   - Run the following command to deploy your application:
     ```bash
     windeployqt tetris.exe
     ```

5. **Test the Deployed Application:**
   - After running `windeployqt`, test the application by running the executable in its deployment directory to ensure all dependencies are correctly deployed.

6. **Distribute the Application:**
   - You can now package the deployed files (including the executable and all copied DLLs and plugins) into a ZIP file, installer, or other distribution formats for distribution.

## Contributing

Contributions are welcome! If you find a bug, have a feature request, or want to improve the code, feel free to open an issue or submit a pull request.

## License

This project is licensed under the Apache-2.0 license - see the [LICENSE](LICENSE) file for details.

## Additional Notes

- Ensure that you have the correct version of Qt and associated build tools for your platform.
- If you encounter issues, check the Qt and compiler documentation or seek assistance on community forums.
- If the application still does not work properly, try running it as an administrator.

Thank you for your interest in the **Tetris** application!
