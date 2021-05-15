// PfSnIsHostingApplication 
 
int __fastcall PfSnIsHostingApplication(unsigned __int16 *a1)
{
  int v2; // r7
  unsigned int v3; // r2
  int v4; // r5
  unsigned int v5; // r1
  unsigned __int16 *v7; // r5
  char *v8; // r0
  unsigned int v9; // r1
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  unsigned __int16 *v13; // r3
  unsigned int v14; // [sp+0h] [bp-20h]

  v14 = wcslen(a1);
  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)dword_637278, 0, 0);
  do
    v5 = __ldrex(dword_637278);
  while ( !v5 && __strex(0x11u, dword_637278) );
  __dmb(0xBu);
  if ( v5 )
    return sub_808880(17);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v7 = &word_637110[wcslen(&word_637110[48]) + 48];
  v8 = wcsstr((char *)&word_637110[48], (char *)a1);
  if ( v8 )
  {
    while ( v8 >= (char *)&word_637110[48] && v8 < (char *)v7 )
    {
      if ( v8 == (char *)&word_637110[48] || *((_WORD *)v8 - 1) == 44 )
      {
        v13 = (unsigned __int16 *)&v8[2 * v14];
        if ( v13 == v7 || *v13 == 44 )
        {
          v2 = 1;
          break;
        }
      }
      v8 = wcsstr(v8 + 2, (char *)a1);
      if ( !v8 )
        break;
    }
  }
  __dmb(0xBu);
  do
    v9 = __ldrex(dword_637278);
  while ( v9 == 17 && __strex(0, dword_637278) );
  if ( v9 != 17 )
    ExfReleasePushLockShared(dword_637278);
  v10 = KeAbPostRelease((unsigned int)dword_637278);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return v2;
}
