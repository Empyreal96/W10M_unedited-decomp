// PopIdleIsDozeS4Enabled 
 
BOOL __fastcall PopIdleIsDozeS4Enabled(_BYTE *a1)
{
  return *(_DWORD *)(PopPolicy + 88) && dword_61EEA4 && a1[6] && a1[22] == 2 && a1[7];
}
