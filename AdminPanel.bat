@echo off
setlocal enabledelayedexpansion

:: ************************************************************************************
:: *                                   Directories                                    *
:: ************************************************************************************

:: For Send Game & Db to Binary option
for %%A in ("%~dp0Server\Source\Bin\") do set "ServerSourceBinPath=%%~fA"
for %%A in ("%~dp0Server\Binary\binary\") do set "SvFilesBinaryPath=%%~fA"

:: For Send Protos to Db (From Release) option
set "DumpProtoReleasePath=%~dp0Proto\"
set "SvFilesShareConfPath=%~dp0Server\Binary\share\conf\"

set "PackPath=%~dp0Client\Binary\pack\"
set "TrPackLocalePath=%PackPath%locale\locale\tr\"
set "EnPackLocalePath=%PackPath%locale\locale\en\"

:: For Generate Symlinks option


:: ************************************************************************************
:: *                                       Menu                                       *
:: ************************************************************************************
:menu
cls
echo --- Yosun Admin Panel ---
echo 1: Send Game ^& Db ^& Qc to Binary
echo 2: Send Protos to DB and Pack
echo 3: Generate symlinks (Executables ^& DLL's)
echo 4: Generate symlinks (locale ^& data folders)
echo 5: Delete symlinks
echo 6: Clear
echo 7: Clear Compiled Quests
echo 8: Make Quests
echo 9: Start
echo 10: Clear Before Zipping (Reduce archive size)
echo 0: Exit
echo.

:: Prompt for user input
set /p choice=Choose an option: 

:: Process user input
if "%choice%"=="1" goto send_files
if "%choice%"=="2" goto send_protos
if "%choice%"=="3" goto generate_symlinks_executables
if "%choice%"=="4" goto generate_symlinks_folders
if "%choice%"=="5" goto delete_symlinks
if "%choice%"=="6" goto clear
if "%choice%"=="7" goto clear_quests
if "%choice%"=="8" goto make_quests
if "%choice%"=="9" goto start
if "%choice%"=="10" goto clear_before_zipping
if "%choice%"=="0" goto exit_script

:: If invalid option, show the menu again
echo Invalid choice, please select a valid option.
pause
goto menu



:: ************************************************************************************
:: *                      1: Send Game & Db & Qc to Binary                       *
:: ************************************************************************************
:send_files
echo Sending Game ^& Db ^& Qc to Binary...
:: Check and create binary directory
if not exist "%SvFilesBinaryPath%" (
    echo [Info]    Binary directory does not exist: "%SvFilesBinaryPath%"
    echo [Info]    Creating binary directory...
    mkdir "%SvFilesBinaryPath%" || (echo [Error] : Failed to create binary directory. Exiting script. & exit /b 1)
    echo [Success] Binary directory created successfully.
    echo.
)

:: Function to copy files from Release
echo [Info]    Copying files from Release folder...
for %%F in (db_Win32_Release.exe db_Win32_Debug.exe game_Win32_Release.exe game_Win32_Debug.exe qc_Win32_Release.exe qc_Win32_Debug.exe) do (
    copy "%ServerSourceBinPath%%%F" "%SvFilesBinaryPath%" >nul
    if errorlevel 1 (
        echo [Error] : Failed to copy "%%F" to "%SvFilesBinaryPath%"
    ) else (
        echo [Success] Copied "%%F" to "%SvFilesBinaryPath%"
    )
)
echo.

echo [Success] All operations completed.
pause
goto menu



:: ************************************************************************************
:: *                       2: Send Protos to Db (From Release)                        *
:: ************************************************************************************
:send_protos
:: %TAB% line uses a tab for indentation.
set "TAB=	"

:: Copy item_proto.txt, mob_proto.txt and dump_proto.exe to each language folder
:: ==== Turkish ====
copy "%DumpProtoReleasePath%item_proto.txt" "%DumpProtoReleasePath%tr" >nul 2>&1 && echo [Success] item_proto.txt%TAB%copied to Release\tr || echo Error copying item_proto.txt to Release\tr
copy "%DumpProtoReleasePath%mob_proto.txt" "%DumpProtoReleasePath%tr" >nul 2>&1 && echo [Success] mob_proto.txt%TAB%%TAB%copied to Release\tr || echo Error copying mob_proto.txt to Release\tr
copy "%DumpProtoReleasePath%dump_proto.exe" "%DumpProtoReleasePath%tr" >nul 2>&1 && echo [Success] dump_proto.exe%TAB%copied to Release\tr || echo Error copying dump_proto.exe to Release\tr
:: ==== English ====
copy "%DumpProtoReleasePath%item_proto.txt" "%DumpProtoReleasePath%en" >nul 2>&1 && echo [Success] item_proto.txt%TAB%copied to Release\en || echo Error copying item_proto.txt to Release\en
copy "%DumpProtoReleasePath%mob_proto.txt" "%DumpProtoReleasePath%en" >nul 2>&1 && echo [Success] mob_proto.txt%TAB%%TAB%copied to Release\en || echo Error copying mob_proto.txt to Release\en
copy "%DumpProtoReleasePath%dump_proto.exe" "%DumpProtoReleasePath%en" >nul 2>&1 && echo [Success] dump_proto.exe%TAB%copied to Release\en || echo Error copying dump_proto.exe to Release\en

:: Execute dump_proto.exe in each language to generate protos and wait until it ends
:: ==== Turkish ====
cd "%DumpProtoReleasePath%tr\"
start /wait "Dump Proto TR" "dump_proto.exe" >nul 2>&1 echo [Success] Turkish item_proto and mob_proto generated || echo Error starting dump_proto.exe in \tr
:: Go back to DumpProtoReleasePath
cd "../../"
:: ==== English ====
cd "%DumpProtoReleasePath%en\"
start /wait "Dump Proto EN" "dump_proto.exe" >nul 2>&1 echo [Success] English item_proto and mob_proto generated || echo Error starting dump_proto.exe in \en
:: Go back to DumpProtoReleasePath
cd "../../"

:: Copy item_names.txt, item_proto.txt, mob_names.txt and mob_proto.txt to Binary\share\conf\ folder
if not exist "%SvFilesShareConfPath%" (
    mkdir "%SvFilesShareConfPath%" || (echo [Error] Failed to create "%SvFilesShareConfPath%" & goto :menu)
)
copy "%DumpProtoReleasePath%en\item_names.txt" "%SvFilesShareConfPath%" >nul 2>&1 && echo [Success] item_names.txt%TAB%copied to Server\Binary\share\conf || echo Error copying item_names.txt to Server\Binary\share\conf
copy "%DumpProtoReleasePath%item_proto.txt" "%SvFilesShareConfPath%" >nul 2>&1 && echo [Success] item_proto.txt%TAB%copied to Server\Binary\share\conf || echo Error copying item_proto.txt to Server\Binary\share\conf
copy "%DumpProtoReleasePath%en\mob_names.txt" "%SvFilesShareConfPath%" >nul 2>&1 && echo [Success] mob_names.txt%TAB%%TAB%copied to Server\Binary\share\conf || echo Error copying mob_names.txt to Server\Binary\share\conf
copy "%DumpProtoReleasePath%mob_proto.txt" "%SvFilesShareConfPath%" >nul 2>&1 && echo [Success] mob_proto.txt%TAB%%TAB%copied to Server\Binary\share\conf || echo Error copying mob_proto.txt to Server\Binary\share\conf

:: Move generated item_proto and mob_proto to each pack/locale/xx
:: ==== Turkish ====
move "%DumpProtoReleasePath%tr\item_proto" "%TrPackLocalePath%" >nul 2>&1 && echo [Success] item_proto%TAB%%TAB%moved to pack/locale/tr || echo Error moving item_proto to pack/locale/tr
move "%DumpProtoReleasePath%tr\mob_proto" "%TrPackLocalePath%" >nul 2>&1 && echo [Success] mob_proto%TAB%%TAB%moved to pack/locale/tr || echo Error moving mob_proto to pack/locale/tr
:: ==== English ====
move "%DumpProtoReleasePath%en\item_proto" "%EnPackLocalePath%" >nul 2>&1 && echo [Success] item_proto%TAB%%TAB%moved to pack/locale/en || echo Error moving item_proto to pack/locale/en
move "%DumpProtoReleasePath%en\mob_proto" "%EnPackLocalePath%" >nul 2>&1 && echo [Success] mob_proto%TAB%%TAB%moved to pack/locale/en || echo Error moving mob_proto to pack/locale/en

:: Delete item_proto.txt, mob_proto.txt and dump_proto.exe from \Release\xx folders
:: ==== Turkish ====
del "%DumpProtoReleasePath%tr\item_proto.txt" >nul 2>&1 && echo [Success] item_proto.txt%TAB%deleted from Release\tr || echo Error deleting dump_proto.exe in \tr
del "%DumpProtoReleasePath%tr\mob_proto.txt" >nul 2>&1 && echo [Success] mob_proto.txt%TAB%%TAB%deleted from Release\tr || echo Error deleting dump_proto.exe in \tr
del "%DumpProtoReleasePath%tr\dump_proto.exe" >nul 2>&1 && echo [Success] dump_proto.exe%TAB%deleted from Release\tr || echo Error deleting dump_proto.exe in \tr
:: ==== English ====
del "%DumpProtoReleasePath%en\item_proto.txt" >nul 2>&1 && echo [Success] item_proto.txt%TAB%deleted from Release\en || echo Error deleting dump_proto.exe in \en
del "%DumpProtoReleasePath%en\mob_proto.txt" >nul 2>&1 && echo [Success] mob_proto.txt%TAB%%TAB%deleted from Release\en || echo Error deleting dump_proto.exe in \en
del "%DumpProtoReleasePath%en\dump_proto.exe" >nul 2>&1 && echo [Success] dump_proto.exe%TAB%deleted from Release\en || echo Error deleting dump_proto.exe in \en

:: Pack the locale pack using PackMakerLite 3.0
cd "%PackPath%"
cmd /c "PackMakerLite_p.bat locale"

goto menu



:: ************************************************************************************
:: *                    3: Generate Symlinks (Executables & DLL's)                    *
:: ************************************************************************************

:generate_symlinks_executables

echo Generating symlinks...

:: Check if script is running with administrator privileges
:: By creating a symlink in a location that requires admin privileges
echo dummy > "%TEMP%\test_symlink.txt"
mklink "%TEMP%\test_symlink_link.txt" "%TEMP%\test_symlink.txt" >nul 2>&1

:: Check if symlink creation was successful
if errorlevel 1 (
    echo You need to run the script as administrator.
    del "%TEMP%\test_symlink.txt" 2>nul
    del "%TEMP%\test_symlink_link.txt" 2>nul
    pause
    goto menu
)

:: Clean up the test symlink after testing (only if the script ran as admin)
del "%TEMP%\test_symlink.txt" 2>nul
del "%TEMP%\test_symlink_link.txt" 2>nul

:: Set base paths
set "base=%~dp0Server\Binary"
set "binary=%base%\binary"
set "share=%base%\share"
set "cores=%base%\cores"
set "quest=%share%\locale\english\quest"

:: Initialize EXITCODE to 0
set EXITCODE=0

:: Create symlinks and check for errors
call :create_symlink "%cores%\db\db_Win32_Release.exe" "%binary%\db_Win32_Release.exe"
call :create_symlink "%cores%\db\db_Win32_Debug.exe" "%binary%\db_Win32_Debug.exe"
call :create_symlink "%cores%\db\item_names.txt" "%share%\conf\item_names.txt"
call :create_symlink "%cores%\db\item_proto.txt" "%share%\conf\item_proto.txt"
call :create_symlink "%cores%\db\mob_names.txt" "%share%\conf\mob_names.txt"
call :create_symlink "%cores%\db\mob_proto.txt" "%share%\conf\mob_proto.txt"
call :create_symlink "%cores%\auth\auth.exe" "%binary%\game_Win32_Release.exe"
call :create_symlink "%cores%\auth\auth_d.exe" "%binary%\game_Win32_Debug.exe"
call :create_symlink "%cores%\ch1\ch1.exe" "%binary%\game_Win32_Release.exe"
call :create_symlink "%cores%\ch1\ch1_d.exe" "%binary%\game_Win32_Debug.exe"
call :create_symlink "%cores%\ch2\ch2.exe" "%binary%\game_Win32_Release.exe"
call :create_symlink "%cores%\ch2\ch2_d.exe" "%binary%\game_Win32_Debug.exe"
call :create_symlink "%cores%\ch99\ch99.exe" "%binary%\game_Win32_Release.exe"
call :create_symlink "%cores%\ch99\ch99_d.exe" "%binary%\game_Win32_Debug.exe"
call :create_symlink "%quest%\qc_Win32_Release.exe" "%binary%\qc_Win32_Release.exe"
call :create_symlink "%quest%\qc_Win32_Debug.exe" "%binary%\qc_Win32_Debug.exe"

:: Symlink DLLs to cores\auth, ch1, ch2, and ch99
for %%d in (auth ch1 ch2 ch99) do (
    call :create_symlink "%cores%\%%d\DevIL-1.7.8.dll" "%binary%\DevIL-1.7.8.dll"
    call :create_symlink "%cores%\%%d\DevIL-1.7.8d.dll" "%binary%\DevIL-1.7.8d.dll"
    call :create_symlink "%cores%\%%d\DevILU-1.7.8.dll" "%binary%\DevILU-1.7.8.dll"
    call :create_symlink "%cores%\%%d\DevILU-1.7.8d.dll" "%binary%\DevILU-1.7.8d.dll"
    call :create_symlink "%cores%\%%d\DevILUT-1.7.8.dll" "%binary%\DevILUT-1.7.8.dll"
    call :create_symlink "%cores%\%%d\DevILUT-1.7.8d.dll" "%binary%\DevILUT-1.7.8d.dll"
)

:: Final check
if %EXITCODE% neq 0 (
    echo Some symlinks could not be created due to permission issues.
) else (
    echo All symlinks created successfully.
)

pause
goto menu



:: ************************************************************************************
:: *                   4: Generate Symlinks (locale & data folders)                   *
:: ************************************************************************************

:generate_symlinks_folders

echo Generating symlinks...

call :check_for_admin_priviledges

:: Set base paths
set "base=%~dp0Server\Binary"
set "share=%base%\share"
set "cores=%base%\cores"

:: Initialize EXITCODE to 0
set EXITCODE=0

:: Symlink locale directory to cores\auth, ch1, ch2, and ch99
for %%d in (auth ch1 ch2 ch99) do (
    call :create_symlink_directory "%cores%\%%d\locale" "%share%\locale"
)

:: Symlink data directory to cores\ch1, ch2, and ch99
for %%d in (ch1 ch2 ch99) do (
    call :create_symlink_directory "%cores%\%%d\data" "%share%\data"
)

:: Final check
if %EXITCODE% neq 0 (
    echo Some symlinks could not be created due to permission issues.
) else (
    echo All symlinks created successfully.
)

pause
goto menu

:create_symlink
:: Parameters: %1 = Symlink path, %2 = Target path

:: Check if the symlink already exists and points to the correct target
if exist "%~1" (
    if /i "%~fs1"=="%~fs2" (
        echo Symlink already exists: %1 -> %2
        goto :eof
    )
    echo Target already exists but is not the correct symlink: %1
    del "%~1" >nul 2>&1
)

:: Create the symlink
mklink /h "%~1" "%~2"
if %ERRORLEVEL% neq 0 (
    echo Failed to create symlink: %1 -> %2
    set EXITCODE=1
)

goto :eof

:create_symlink_directory
:: Parameters: %1 = Directory Symlink path, %2 = Directory Target path

:: Check if the directory symlink already exists and points to the correct target
if exist "%~1" (
    if /i "%~fs1"=="%~fs2" (
        echo Directory symlink already exists: %1 -> %2
        goto :eof
    )
    echo Target directory already exists but is not the correct symlink: %1
    rmdir "%~1" >nul 2>&1
)

:: Create the directory symlink
mklink /D "%~1" "%~2"
if %ERRORLEVEL% neq 0 (
    echo Failed to create directory symlink: %1 -> %2
    set EXITCODE=1
)

goto :eof

:check_for_admin_priviledges
:: Check if script is running with administrator privileges
:: By creating a symlink in a location that requires admin privileges
echo dummy > "%TEMP%\test_symlink.txt"
mklink "%TEMP%\test_symlink_link.txt" "%TEMP%\test_symlink.txt" >nul 2>&1

:: Check if symlink creation was successful
if errorlevel 1 (
    echo You need to run the script as administrator.
    del "%TEMP%\test_symlink.txt" 2>nul
    del "%TEMP%\test_symlink_link.txt" 2>nul
    pause
    goto menu
)

:: Clean up the test symlink after testing (only if the script ran as admin)
del "%TEMP%\test_symlink.txt" 2>nul
del "%TEMP%\test_symlink_link.txt" 2>nul

goto :eof



:: ************************************************************************************
:: *                                5: Delete Symlinks                                *
:: ************************************************************************************
:delete_symlinks
echo Deleting all symlinks...
cd "%~dp0Server/Binary/cores/db"
del db_Win32_Release.exe
del db_Win32_Debug.exe
del item_names.txt
del item_proto.txt
del mob_names.txt
del mob_proto.txt

cd "../auth"
del auth.exe
del auth_d.exe
del DevIL-1.7.8.dll
del DevIL-1.7.8d.dll
del DevILU-1.7.8.dll
del DevILU-1.7.8d.dll
del DevILUT-1.7.8.dll
del DevILUT-1.7.8d.dll
rmdir /S /Q "locale"

cd "../ch1"
del ch1.exe
del ch1_d.exe
del DevIL-1.7.8.dll
del DevIL-1.7.8d.dll
del DevILU-1.7.8.dll
del DevILU-1.7.8d.dll
del DevILUT-1.7.8.dll
del DevILUT-1.7.8d.dll
rmdir /S /Q "locale"
rmdir /S /Q "data"

cd "../ch2"
del ch2.exe
del ch2_d.exe
del DevIL-1.7.8.dll
del DevIL-1.7.8d.dll
del DevILU-1.7.8.dll
del DevILU-1.7.8d.dll
del DevILUT-1.7.8.dll
del DevILUT-1.7.8d.dll
rmdir /S /Q "locale"
rmdir /S /Q "data"

cd "../ch99"
del ch99.exe
del ch99_d.exe
del DevIL-1.7.8.dll
del DevIL-1.7.8d.dll
del DevILU-1.7.8.dll
del DevILU-1.7.8d.dll
del DevILUT-1.7.8.dll
del DevILUT-1.7.8d.dll
rmdir /S /Q "locale"
rmdir /S /Q "data"

cd "../../share/locale/english/quest"
del qc_Win32_Release.exe
del qc_Win32_Debug.exe


pause
goto menu



:: ************************************************************************************
:: *                                     6: Clear                                     *
:: ************************************************************************************
:clear
echo Clearing...
cd "%~dp0Server/Binary/cores/db"
for /D %%i in (log\*) do (
    if exist "%%i" rd /s /q "%%i"
)
del syserr.txt
del syslog.txt
del PTS.txt

cd "../auth"
for /D %%i in (log\*) do (
    if exist "%%i" rd /s /q "%%i"
)
del packet_info.txt
del syserr.txt
del syslog.txt
del PTS.txt
del p2p_packet_info.txt

cd "../ch1"
for /D %%i in (log\*) do (
    if exist "%%i" rd /s /q "%%i"
)
del packet_info.txt
del syserr.txt
del syslog.txt
del PTS.txt
del p2p_packet_info.txt

cd "../ch2"
for /D %%i in (log\*) do (
    if exist "%%i" rd /s /q "%%i"
)
del packet_info.txt
del syserr.txt
del syslog.txt
del PTS.txt
del p2p_packet_info.txt

cd "../ch99"
for /D %%i in (log\*) do (
    if exist "%%i" rd /s /q "%%i"
)
del packet_info.txt
del syserr.txt
del syslog.txt
del PTS.txt
del p2p_packet_info.txt

pause
goto menu



:: ************************************************************************************
:: *                             7: Clear Compiled Quests                             *
:: ************************************************************************************
:clear_quests
echo Deleting all compiled quests...
cd "%~dp0Server/Binary/share/locale/english/quest"
rmdir /S /Q "object"
rmdir /S /Q "__pycache__"
rmdir /S /Q "pre_qc"

cd "../../../../cores/auth/locale/english/quest"
rmdir /S /Q "object"
rmdir /S /Q "__pycache__"
rmdir /S /Q "pre_qc"

cd "../../../../ch1/locale/english/quest"
rmdir /S /Q "object"
rmdir /S /Q "__pycache__"
rmdir /S /Q "pre_qc"

cd "../../../../ch2/locale/english/quest"
rmdir /S /Q "object"
rmdir /S /Q "__pycache__"
rmdir /S /Q "pre_qc"

cd "../../../../ch99/locale/english/quest"
rmdir /S /Q "object"
rmdir /S /Q "__pycache__"
rmdir /S /Q "pre_qc"

pause
goto menu


:: ************************************************************************************
:: *                                  8: Make Quests                                  *
:: ************************************************************************************
:make_quests
echo Compiling Quests...

cd "%~dp0Server/Binary/share/locale/english/quest"
python make.py

pause
goto menu



:: ************************************************************************************
:: *                                 9: Start Server                                  *
:: ************************************************************************************
:start
echo Starting the process...

cd "%~dp0Server/Binary/cores/db"
start "db" "db_Win32_Release.exe"

cd "../auth"
start "auth" "auth.exe"

cd "../ch1"
start "ch1" "ch1.exe"

cd "../ch2"
start "ch2" "ch2.exe"

cd "../ch99"
start "ch99" "ch99.exe"

goto menu



:: ************************************************************************************
:: *                             10: Clear Before Zipping                             *
:: ************************************************************************************
:clear_before_zipping
:: Go to script directory
cd "%~dp0"

echo ===========================================
echo [1/6] Removing Visual Studio cache...
echo ===========================================
if exist ".vs" (
    echo Deleting .vs folder...
    rmdir /s /q ".vs"
) else (
    echo .vs folder not found.
)

cd "Client/Binary/pack"
echo.
echo ===========================================
echo [2/6] Clearing pack folders...
echo ===========================================
for %%F in (ETC Icon locale Maps Property Root Sound Textureset) do (
    if exist "%%F" (
        echo Deleting %%F...
        rmdir /s /q "%%F"
    ) else (
        echo %%F folder not found.
    )
)

cd "../screenshot"
echo.
echo ===========================================
echo [3/6] Clearing screenshots...
echo ===========================================
for %%i in (*) do (
    if exist "%%i" (
        echo Deleting %%i...
        del /q "%%i"
    )
)
echo Screenshots cleared.

cd "../../Source"
echo.
echo ===========================================
echo [4/6] Removing Debug, Distribute, and Release folders from projects...
echo ===========================================
for /d /r %%D in (Debug Distribute Release) do (
    if exist "%%D" (
        echo Deleting %%D...
        rmdir /s /q "%%D"
    )
)

cd "../../Tools/DumpProto"
for %%F in (Debug Release) do (
    if exist "%%F" (
        echo Deleting %%F...
        rmdir /s /q "%%F"
    ) else (
        echo %%F folder not found.
    )
)

echo Build folders cleared.

cd "../../Tools/EPack32"
echo.
echo ===========================================
echo [5/6] Removing Property folder in EPack32...
echo ===========================================
if exist "Property" (
    echo Deleting Property...
    rmdir /s /q "Property"
) else (
    echo Property folder not found.
)

echo.
echo ===========================================
echo [6/6] All cleaning operations completed.
echo ===========================================

pause
goto menu



:: ************************************************************************************
:: *                                     0: Exit                                      *
:: ************************************************************************************
:exit_script
echo Exiting admin panel...
exit /b
