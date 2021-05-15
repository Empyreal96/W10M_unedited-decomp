// NtQuerySystemInformation 
 
int __fastcall NtQuerySystemInformation(int a1, int a2, int a3, int a4)
{
  int *v5; // r1
  int v6; // r2
  __int16 v8; // r3
  int v9; // [sp+8h] [bp-10h] BYREF

  v9 = a4;
  if ( a1 <= 83 )
  {
    if ( a1 != 83 && a1 != 61 && a1 != 8 && a1 != 23 && a1 != 42 )
    {
      if ( a1 != 73 )
      {
LABEL_8:
        v5 = 0;
        v6 = 0;
        return ExpQuerySystemInformation(a1, v5, v6, a2);
      }
      v8 = 0;
LABEL_16:
      v5 = &v9;
      v6 = 2;
      LOWORD(v9) = v8;
      return ExpQuerySystemInformation(a1, v5, v6, a2);
    }
LABEL_15:
    v8 = *(unsigned __int8 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x99C);
    goto LABEL_16;
  }
  if ( a1 == 100 )
    goto LABEL_15;
  if ( a1 != 107 )
  {
    if ( a1 == 108 )
      goto LABEL_15;
    if ( a1 != 121 )
    {
      if ( a1 != 141 )
        goto LABEL_8;
      goto LABEL_15;
    }
  }
  return -1073741821;
}
