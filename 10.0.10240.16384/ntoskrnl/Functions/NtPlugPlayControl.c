// NtPlugPlayControl 
 
int NtPlugPlayControl(unsigned int a1, ...)
{
  int v1; // r9
  unsigned int v3; // r3
  int v4; // r8
  int *v5; // r5
  int v6; // r4
  unsigned int v7; // r6
  int v8; // r0
  int v9; // r0
  int v11[8]; // [sp+8h] [bp-20h] BYREF
  int varg_r1; // [sp+34h] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+34h] [bp+Ch]
  int varg_r2; // [sp+38h] [bp+10h]
  int varg_r3; // [sp+3Ch] [bp+14h]
  va_list va1; // [sp+40h] [bp+18h] BYREF

  va_start(va1, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(va1, _DWORD);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  v11[0] = varg_r2;
  v11[1] = varg_r3;
  v1 = varg_r2;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(char *)(v3 + 346);
  if ( !*(_BYTE *)(v3 + 346) )
  {
    if ( a1 < 0x18 )
    {
      v5 = &PlugPlayHandlerTable[4 * a1];
      if ( *v5 != a1 )
        return -1073741595;
      if ( v5 )
      {
        if ( !v5[2] )
          return -1073741822;
        if ( v5[1] != varg_r2 )
          return -1073741776;
        if ( PsIsCurrentThreadInServerSilo() && !*((_BYTE *)v5 + 12) )
          JUMPOUT(0x7C5B46);
        v11[0] = 0;
        v6 = PiControlMakeUserModeCallersCopy(v11);
        if ( v6 >= 0 )
        {
          v7 = v11[0];
          v8 = ((int (__fastcall *)(unsigned int, int, int, int, int, int))v5[2])(a1, v11[0], v1, v4, v4, 1);
          v6 = v8;
          if ( (v8 & 0xC0000000) != -1073741824 || v8 == -1073741789 )
          {
            v9 = PiControlMakeUserModeCallersCopy((int *)varg_r1a);
            if ( v9 < 0 )
              v6 = v9;
          }
          if ( v6 == -1073741738 )
            v6 = -1073741810;
          if ( v4 )
          {
            if ( v7 )
              ExFreePoolWithTag(v7);
          }
        }
        return v6;
      }
    }
    return -1073741585;
  }
  return sub_7C5B34();
}
