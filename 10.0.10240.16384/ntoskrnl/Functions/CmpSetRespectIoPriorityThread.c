// CmpSetRespectIoPriorityThread 
 
BOOL __fastcall CmpSetRespectIoPriorityThread(int a1, char a2)
{
  int v2; // r2
  BOOL result; // r0

  v2 = *(_DWORD *)(a1 + 964);
  result = (v2 & 0x20) != 0;
  *(_DWORD *)(a1 + 964) = ((unsigned __int8)v2 ^ (unsigned __int8)(32 * a2)) & 0x20 ^ v2;
  return result;
}
