+------------------------------------------------------------+
|                * Kaptan Yosun's Pureline *                 |
+------------------------------------------------------------+

+--------------------------------------------+---------------+
| General Information                        | Version       |
+--------------------------------------------+---------------+
| Base                                       | [Mainline]    |
| DirectX                                    | [9Ex]         |
| Granny                                     | [2.11.8]      |
+--------------------------------------------+---------------+

+------------------------------+---------+--------+----------+
| Extern Information           | Server  | Client | Version  |
|------------------------------+---------+--------+----------+
| MiniLZO                      | YES     | NO     | [2.10]   |
| Boost                        | YES     | YES    | [1.88.0] |
| CryptoPP                     | YES     | YES    | [8.9.0]  |
| SpeedTree                    | NO      | YES    | [1.6.0]  |
| Dear ImGui                   | NO      | YES    | [1.92.2] |
+------------------------------+---------+--------+----------+

+-----------------------------------+--------+--------+------+
| New Code                          | Server | Client | Pack |
+-----------------------------------+--------+--------+------+
| [REVERSED] ABORT_TRACEBACK_UPDATE | NO     | YES    | NO   | More detailed Python traceback with line printing.
| [REVERSED] SAVE_CAMERA_MODE       | NO     | YES    | YES  | Save near or far camera mode on exit.
| [REVERSED] ATLAS_MARK_INFO        | YES    | YES    | YES  | Pull NPC positions from Client instead of ServerFiles.
| [REVERSED] CLIENT_LOCALE_STRING   | YES    | YES    | NO   | This system is the basis of Multilanguage.
| MULTI_LANGUAGE_MINIMAL            | YES    | YES    | NO   | Additions to Client locale string to make many aspects of the game multi language.
| DYNAMIC_OBJECT_SHADOWS            | NO     | YES    | NO   | Dynamic shadows for property objects.
| DYNAMIC_TREE_SHADOWS              | NO     | YES    | NO   | Dynamic shadows for trees.
| YOSUN_ADMIN_PANEL                 | NO     | YES    | NO   | Easy ImGUI GM tools.
| SHADERS                           | NO     | YES    | YES  | Shader Manager.
|                                   |        |        |      |
+-----------------------------------+--------+--------+------+

+-----------------------------------+--------+--------+------+
| New Code [Small]                  | Server | Client | Pack |
+-----------------------------------+--------+--------+------+
|                                   |        |        |      |
+-----------------------------------+--------+--------+------+

+-----------------------------------+--------+--------+------+
| Removed Systems/Significant Code  | Server | Client | Pack |
+-----------------------------------+--------+--------+------+
| Xtrap                             | YES    | YES    | NO   |
| Hackshield                        | YES    | YES    | NO   |
| PC_Bang            [+ Dump Proto] | YES    | YES    | YES  |
| Lottery            [+ Dump Proto] | YES    | YES    | YES  |
| Teen                              | YES    | NO     | NO   |
| nProtect_GameGuard                | NO     | YES    | NO   |
| Software Tiling                   | NO     | YES    | YES  |
| libserverkey                      | YES    | NO     | NO   |
| BlockCountryIp                    | YES    | NO     | NO   |
| Mobile - SMS                      | YES    | YES    | YES  |
| Auth_Brazil & Auth_Japan          | YES    | NO     | NO   |
| Virtual Keyboard                  | NO     | NO     | YES  |
| Auction                           | YES    | YES    | YES  |
| passpod                           | YES    | YES    | YES  |
| matrix_card                       | YES    | YES    | YES  |
| Monarch + Castle / Siege          | YES    | NO     | NO   |
| Threeway_War                      | YES    | NO     | NO   |
| OpenID                            | YES    | YES    | YES  |
| Sequence                          | YES    | YES    | YES  |
| Vcard                             | YES    | NO     | NO   |
| Over9Refine                       | YES    | NO     | NO   |
| SpeedServer                       | YES    | NO     | NO   |
| Panama                            | YES    | YES    | NO   |
| CSHybridCrypt                     | YES    | YES    | NO   |
|                                   |        |        |      |
+-----------------------------------+--------+--------+------+

+-----------------------------------+--------+--------+------+
| Removed Small/Insignificant Code  | Server | Client | Pack |
+-----------------------------------+--------+--------+------+
| Netmarble                         | YES    | NO     | NO   |
| HammerOfTor                       | YES    | NO     | NO   |
| Roulette                          | YES    | NO     | NO   |
| VIETNAM_CONVERT_WEAPON_VNUM       | NO     | NO     | NO   |
| Hotbackup                         | YES    | NO     | NO   |
| AlphaFog                          | NO     | YES    | NO   |
|                                   |        |        |      |
+-----------------------------------+--------+--------+------+

+-------------------------------+----------------------------+
| New Defines                   | Location                   |
+-------------------------------+----------------------------+
|                               |                            |
+-------------------------------+----------------------------+

+------------------------------------------+-----------------+
| New Configurable Options                 | Location        |
+------------------------------------------+---------------- +
|                                          |                 |
+------------------------------------------+-----------------+

+------------------------------------------------------------+
|                       * Bug Fixes *                        |
+------------------------------------------------------------+
(TODO) [REVERSED] FOG_FIX          : Official fog mode fix to toggle fog on and off.
[REVERSED] LEVEL_UPDATE_FIX        : Fixes an old bug where level is not immediately updated on screen. [Client + Server]
[FOG_TGA FIX]               : Fixes client crashing without a syserr while warping.

[YOSUN_PACK_FIX_001]               : "Python int too large to convert to C long" error fix.

[YOSUN_SERVER_FIX_001]             : Fixed a typo
[YOSUN_SERVER_FIX_002]             : Blocked private shop creation while riding which causes a visual bug.

[YOSUN_WORLDEDITOR_FIX_001]        : Fixes crash when a .spt SpeedTree model is selected on brush.

+------------------------------------------------------------+
|                          * TODO *                          |
+------------------------------------------------------------+


+------------------------------------------------------------+
|                * Commands to set up MySQL *                |
+------------------------------------------------------------+
CREATE DATABASE account;
CREATE DATABASE log;
CREATE DATABASE common;
CREATE DATABASE player;
GRANT ALL PRIVILEGES ON *.* TO 'kaptan'@'localhost' WITH GRANT OPTION;

+------------------------------------------------------------+
|                  * Commands for GitHub *                   |
+------------------------------------------------------------+
Remove cached files in case gitignore doesn't ignore them:    git rm -r --cached *
Generate a Diff file of the latest commit:                    git show --pretty=format:%b > burayaisimyaz.diff