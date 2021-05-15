// EtwpAddDebugInfoEvents 
 
int __fastcall EtwpAddDebugInfoEvents(int result, int a2, int a3, int a4, char a5)
{
  int v5; // r7
  int v7; // r5
  int v8; // r10
  unsigned __int8 *v9; // r8
  int v10; // r4
  unsigned int v11; // r2
  int *v12; // r4
  int v13; // r8
  int v14; // r7
  unsigned int *v15; // r4
  unsigned int v16; // r1
  int v17; // [sp+10h] [bp-38h] BYREF
  int v18; // [sp+14h] [bp-34h]
  int v19; // [sp+18h] [bp-30h]
  int v20; // [sp+1Ch] [bp-2Ch]

  v5 = result;
  v7 = a3 - *(_DWORD *)(a2 + 48);
  v18 = a2;
  v19 = result;
  if ( !a4 )
    return sub_80BB34();
  if ( (a5 & 1) != 0 )
  {
    result = EtwpAddEventToBuffer(a2, 66, a4, "10240.16384.armfre.th1.150709-1700", 35, v7, &v17);
    if ( result < 0 )
      return result;
    v7 -= v17;
  }
  v8 = a5 & 2;
  v20 = v8;
  if ( (a5 & 2) != 0 )
  {
    v9 = (unsigned __int8 *)(v5 + 504);
    result = KeAbPreAcquire(v5 + 504, 0, 0);
    v10 = result;
    do
      v11 = __ldrex(v9);
    while ( __strex(v11 | 1, v9) );
    __dmb(0xBu);
    if ( (v11 & 1) != 0 )
      result = ExfAcquirePushLockExclusiveEx((_DWORD *)(v5 + 504), result, v5 + 504);
    if ( v10 )
      *(_BYTE *)(v10 + 14) |= 1u;
  }
  v12 = *(int **)(v5 + 80);
  v13 = v5 + 80;
  if ( v12 != (int *)(v5 + 80) )
  {
    v14 = v18;
    do
    {
      if ( (a5 & 4) == 0 || !*((_BYTE *)v12 + 8) )
      {
        result = EtwpAddEventToBuffer(v14, 64, a4, v12 + 5, v12[3] - 4, v7, &v17);
        if ( result < 0 )
          break;
        v7 -= v17;
      }
      v12 = (int *)*v12;
    }
    while ( v12 != (int *)v13 );
    v5 = v19;
    v8 = v20;
  }
  if ( v8 )
  {
    v15 = (unsigned int *)(v5 + 504);
    __dmb(0xBu);
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 - 1, v15) );
    if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v5 + 504));
    result = KeAbPostRelease(v5 + 504);
  }
  return result;
}
