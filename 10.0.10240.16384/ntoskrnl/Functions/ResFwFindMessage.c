// ResFwFindMessage 
 
int __fastcall ResFwFindMessage(unsigned int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5[2]; // [sp+8h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  if ( dword_619090
    && *(_DWORD *)dword_619090
    && RtlFindMessage(*(_DWORD *)dword_619090, 11, 0, a1, v5) >= 0
    && (*(_WORD *)(v5[0] + 2) & 1) != 0 )
  {
    result = v5[0] + 4;
  }
  else
  {
    result = 0;
  }
  return result;
}
