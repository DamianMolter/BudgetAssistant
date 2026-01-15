# Personal Budget Assistant

A console-based personal finance management application written in C++ that helps users track their income and expenses with comprehensive budgeting features.

## Features

### User Management
- **User Registration**: Create new user accounts with secure login credentials
- **User Authentication**: Secure login system with password protection (3 login attempts)
- **Password Management**: Change password functionality for existing users
- **Session Management**: Login/logout capabilities with user session tracking

### Budget Tracking
- **Income Management**: Add and track income entries with date, description, and amount
- **Expense Management**: Record expenses with detailed information
- **Flexible Date Entry**: Option to use today's date or specify custom dates
- **Data Persistence**: All financial data saved to XML files

### Financial Reports
- **Current Month Summary**: View income, expenses, and balance for the current month
- **Previous Month Summary**: Review last month's financial activity
- **Custom Period Reports**: Generate reports for any date range
- **Detailed Listings**: View all recorded incomes and expenses

## Technical Architecture

### Object-Oriented Design
The application follows OOP principles with clear separation of concerns:

- **BudgetMainApp**: Main application controller managing user and budget operations
- **UserManager**: Handles all user-related operations
- **BudgetManager**: Manages financial operations and reporting
- **File I/O Classes**: Separate classes for user and operation file management

### Key Components

#### Core Classes
- `BudgetMainApp` - Application entry point and menu system
- `UserManager` - User registration, login, and authentication
- `BudgetManager` - Income/expense tracking and financial reporting
- `User` - User data model
- `Operation` - Financial transaction data model

#### Data Management
- `UserFile` - User data persistence (XML)
- `OperationFile` - Income/expense data persistence (XML)
- `File` - Base file operations class

#### Utility Classes
- `DateMethods` - Date validation, conversion, and calculations
- `Utils` - Input handling and string utilities

### Data Storage
- **XML Format**: All data stored in XML format using CMarkup library
- **Files**:
  - `users.xml` - User account information
  - `incomes.xml` - Income transactions
  - `expenses.xml` - Expense transactions

## Date Handling

The application includes sophisticated date management:
- Date validation (format: YYYY-MM-DD)
- Leap year calculation
- Month length calculations
- Date range validation
- Automatic current month/previous month period detection
- Date sorting for chronological reports

## Technical Requirements

- **Language**: C++ (C++11 or later recommended)
- **Platform**: Windows (uses `windows.h` for system commands)
- **External Library**: CMarkup (for XML file operations)

## Build and Run

### Compilation
Compile all `.cpp` files together with appropriate C++ compiler flags:

```bash
g++ -o BudgetAssistant *.cpp -std=c++11
```

### Execution
```bash
./BudgetAssistant
```

## Menu Structure

### Main Menu (Not Logged In)
1. Register
2. Login
9. Exit Program

### User Menu (Logged In)
1. Add Income
2. Add Expense
3. Current Month Balance
4. Previous Month Balance
5. Custom Period Balance
6. Change Password
7. Logout

## Data Flow

1. **Registration**: User details → UserManager → UserFile → users.xml
2. **Login**: Credentials → UserManager → Authentication → Session Creation
3. **Add Transaction**: Operation data → BudgetManager → OperationFile → XML file
4. **Generate Report**: Date range → BudgetManager → Filter operations → Calculate totals

## Security Features

- Password protection for user accounts
- Limited login attempts (3 attempts maximum)
- User-specific data isolation
- Session-based access control

## Code Organization

```
├── Main Application
│   ├── main.cpp
│   ├── BudgetMainApp.cpp/h
│
├── User Management
│   ├── UserManager.cpp/h
│   ├── User.cpp/h
│   ├── UserFile.cpp/h
│
├── Budget Management
│   ├── BudgetManager.cpp/h
│   ├── Operation.cpp/h
│   ├── OperationFile.cpp/h
│
├── Utilities
│   ├── DateMethods.cpp/h
│   ├── Utils.cpp/h
│   ├── File.cpp/h
│
└── External Library
    └── Markup.h (CMarkup)
```

## Design Patterns Used

- **Composition**: BudgetMainApp contains UserManager and BudgetManager
- **Inheritance**: File operations hierarchy (File → UserFile/OperationFile)
- **Static Utility Classes**: DateMethods and Utils provide helper functions
- **Encapsulation**: Private data members with public accessors

## Future Enhancement Possibilities

- GUI implementation
- Database integration
- Multi-currency support
- Budget categories and tags
- Data export (PDF, CSV)
- Statistical analysis and charts
- Recurring transactions
- Budget goals and alerts

## Notes

- All text output is in Polish (menu items, prompts, messages)
- Date format: YYYY-MM-DD
- Decimal separator: Both comma and dot supported (automatically converted)
- User IDs and Operation IDs are auto-incremented

## License

This project appears to be an educational/personal project. Please add appropriate license information if needed.