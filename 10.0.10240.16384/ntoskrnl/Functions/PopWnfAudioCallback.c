// PopWnfAudioCallback 
 
int PopWnfAudioCallback(int a1, int a2, int a3, ...)
{
  int v3; // r4
  int v5; // r0
  unsigned int v6; // [sp+0h] [bp-20h] BYREF
  unsigned int v7[6]; // [sp+8h] [bp-18h] BYREF
  int varg_r3; // [sp+34h] [bp+14h] BYREF
  va_list varg_r3a; // [sp+34h] [bp+14h]
  int v10; // [sp+38h] [bp+18h]
  _BYTE *v11; // [sp+3Ch] [bp+1Ch]
  va_list va1; // [sp+40h] [bp+20h] BYREF

  va_start(va1, a3);
  va_start(varg_r3a, a3);
  varg_r3 = va_arg(va1, _DWORD);
  v10 = va_arg(va1, _DWORD);
  v11 = va_arg(va1, _BYTE *);
  v6 = 8;
  v3 = ExQueryWnfStateData(a1, (int *)varg_r3a, (int)v7, &v6);
  if ( v3 < 0 )
    return sub_7F35CC();
  if ( v6 < 8 )
    return 0;
  PopAcquirePolicyLock();
  if ( !*v11 )
  {
    if ( ((v7[0] >> 1) & 1) != 0 )
    {
      v5 = 1;
      goto LABEL_7;
    }
    if ( !*v11 )
      goto LABEL_8;
  }
  if ( ((v7[0] >> 1) & 1) == 0 )
  {
    v5 = 0;
LABEL_7:
    *v11 = v5;
    PopAudioAccountingCallback(v5);
  }
LABEL_8:
  PopReleasePolicyLock();
  return v3;
}
