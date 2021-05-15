// NtDelayExecution 
 
int __fastcall NtDelayExecution(int a1, unsigned int *a2)
{
  char v2; // r4
  unsigned int v4; // [sp+8h] [bp-18h] BYREF
  unsigned int v5; // [sp+Ch] [bp-14h]
  int vars8; // [sp+28h] [bp+8h]
  unsigned int *anonymous2; // [sp+2Ch] [bp+Ch]

  vars8 = a1;
  anonymous2 = a2;
  LOBYTE(vars8) = a1;
  v2 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v2 )
  {
    if ( ((unsigned __int8)a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v4 = *a2;
    v5 = a2[1];
  }
  else
  {
    v4 = *a2;
    v5 = a2[1];
  }
  return KeDelayExecutionThread(v2, a1, &v4);
}
