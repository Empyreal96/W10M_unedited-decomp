// EtwpGetProcessAppSessionGuid 
 
int __fastcall EtwpGetProcessAppSessionGuid(_DWORD *a1, int a2)
{
  int result; // r0

  *(_DWORD *)a2 = a1[44];
  result = PsGetProcessSessionId((int)a1);
  *(_WORD *)(a2 + 4) = result;
  *(_WORD *)(a2 + 6) = MEMORY[0xFFFF92C4];
  *(_DWORD *)(a2 + 8) = a1[50];
  *(_DWORD *)(a2 + 12) = a1[51];
  return result;
}
