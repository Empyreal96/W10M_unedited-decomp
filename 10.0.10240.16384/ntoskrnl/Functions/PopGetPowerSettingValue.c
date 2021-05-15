// PopGetPowerSettingValue 
 
int __fastcall PopGetPowerSettingValue(int a1, int a2, int a3, int a4, int a5, unsigned int *a6)
{
  int v9; // r6
  int v10; // r0
  unsigned __int8 v11; // r8
  unsigned int v12; // r4
  int v14; // r0
  int v15; // r4
  unsigned int v16; // r1
  int v17; // r1
  unsigned int v18; // r2

  v9 = KeAbPreAcquire((unsigned int)&PopSettingLock, 0, 0);
  v10 = KfRaiseIrql(1);
  v11 = v10;
  do
    v12 = __ldrex((unsigned __int8 *)&PopSettingLock);
  while ( __strex(v12 & 0xFE, (unsigned __int8 *)&PopSettingLock) );
  __dmb(0xBu);
  if ( (v12 & 1) == 0 )
    return sub_528EE0();
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  dword_61F324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61F33C = v10;
  if ( a3 != 1 && a3 )
    a3 = dword_61EC0C;
  v14 = PopFindPowerSettingConfiguration(a1, -1);
  if ( v14 && (v17 = *(_DWORD *)(v14 + 4 * a3 + 48)) != 0 )
  {
    v18 = *(_DWORD *)(v17 + 4);
    *a6 = v18;
    if ( v18 > 4 )
    {
      v15 = -1073741306;
    }
    else
    {
      v15 = 0;
      memmove(a4, v17 + 12, v18);
    }
  }
  else
  {
    v15 = -1073741811;
  }
  dword_61F324 = 0;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&PopSettingLock);
  while ( !v16 && __strex(1u, (unsigned int *)&PopSettingLock) );
  if ( v16 )
    ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v16);
  KfLowerIrql(v11);
  KeAbPostRelease((unsigned int)&PopSettingLock);
  return v15;
}
