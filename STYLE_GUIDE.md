# Style Guide for Tetris

This document outlines the coding style and conventions to follow for the **Tetris** project. Consistent code style is essential for readability and maintainability, especially when working in teams or on open-source projects.

## General Guidelines

- **Follow a consistent coding style**: Maintain the conventions used throughout the existing codebase.
- **Use meaningful names**: Choose clear and descriptive names for variables, functions, and classes. Keep names relevant to their purpose within the Tetris game.
- **Write clear and concise comments**: Comment on code when necessary, especially to explain complex logic, game mechanics, or decisions that may not be immediately clear.

## Coding Conventions

### C++ Style

- **Indentation**: Use 4 spaces for indentation. Avoid using tabs.
- **Line Length**: Try to limit lines to 80 characters to improve readability.
- **Braces**: Follow the Allman style for braces, keeping them on a new line:

  ```cpp
  // Correct
  if (gameOver) 
  {
      // Game over logic
  } 
  else 
  {
      // Continue game logic
  }

  // Incorrect
  if (gameOver) {
      // Game over logic
  } else {
      // Continue game logic
  }
