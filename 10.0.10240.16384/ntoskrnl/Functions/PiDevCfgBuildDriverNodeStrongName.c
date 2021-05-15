// PiDevCfgBuildDriverNodeStrongName 
 
int __fastcall PiDevCfgBuildDriverNodeStrongName(unsigned __int16 *a1, int a2, int a3, _DWORD *a4)
{
  int v5; // r5
  int v6; // r4
  int v10; // r4
  int v11; // r4
  int v13; // [sp+20h] [bp-28h] BYREF
  unsigned int v14; // [sp+24h] [bp-24h] BYREF
  int v15; // [sp+28h] [bp-20h] BYREF
  int v16; // [sp+2Ch] [bp-1Ch]

  v5 = a1[22] + a1[18];
  v6 = a1[10];
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  if ( (unsigned int)(v6 + v5 + 92) > 0xFFFE )
  {
    v11 = -1073741562;
  }
  else
  {
    LOWORD(v15) = v6 + v5 + 90;
    HIWORD(v15) = v6 + v5 + 92;
    v16 = ExpAllocateStringRoutine(HIWORD(v15));
    if ( v16 )
    {
      if ( *(_DWORD *)(a2 + 4) && RtlHashUnicodeString((unsigned __int16 *)a2, 1, 0, (unsigned int *)&v13) >= 0 )
        v10 = v13;
      else
        v10 = 0;
      if ( *(_DWORD *)(a3 + 4) )
        RtlHashUnicodeString((unsigned __int16 *)a3, 1, 0, &v14);
      v11 = RtlUnicodeStringPrintf(&v15, (int)L"%wZ:%08x%08x:%wZ:%u.%u.%u.%u:%wZ", (int)(a1 + 10), v10);
      if ( v11 >= 0 )
      {
        *a4 = v15;
        a4[1] = v16;
        v15 = 0;
        v16 = 0;
      }
    }
    else
    {
      v11 = -1073741670;
    }
  }
  RtlFreeAnsiString(&v15);
  return v11;
}
