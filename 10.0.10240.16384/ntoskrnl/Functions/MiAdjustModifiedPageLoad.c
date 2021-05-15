// MiAdjustModifiedPageLoad 
 
_DWORD *__fastcall MiAdjustModifiedPageLoad(_DWORD *result, int a2, char a3)
{
  signed int *v3; // r4
  unsigned int v4; // r6
  unsigned int v5; // r3
  _DWORD *v6; // r7
  unsigned int v7; // r5
  unsigned int v8; // r3
  signed int v10; // lr
  unsigned int v11; // r1
  int v12; // r8
  unsigned int v13; // r3
  unsigned int v14; // r2
  signed int v15; // r3
  signed int v16; // r3
  int v17; // r2
  int v18; // r3
  int v19; // r5
  _DWORD *v20; // r8
  int v21; // r6
  char v23[40]; // [sp+8h] [bp-28h] BYREF

  v3 = result + 118;
  v4 = result[1030];
  v5 = result[928];
  v6 = result;
  v7 = v5 >> 5;
  if ( v5 >> 5 <= 0x4000 )
    v7 = 0x4000;
  v8 = v5 >> 4;
  if ( v8 < v7 )
    v7 = v8;
  v10 = a2;
  v11 = result[320] + result[288];
  v12 = 0;
  if ( v11 <= 0x4E20 || v4 >= v11 / 0xA )
  {
    if ( v4 >= v7 )
    {
      v12 = v7 >> 1;
    }
    else
    {
      v13 = 15 * (result[119] >> 4);
      v14 = v13 + (v4 >> 4);
      result[119] = v14;
      if ( v13 <= v14 )
      {
        if ( v4 < 0x320 )
        {
LABEL_28:
          *v3 = 0;
          goto LABEL_15;
        }
        v15 = *v3;
        if ( v14 > v4 )
          v16 = v15 - v14 + v4;
        else
          v16 = v15 + v14 - v4;
        v17 = v16 + v4;
        *v3 = v16;
        *v3 = v16 + v4;
        if ( v16 <= (int)(v16 + v4) )
        {
          v18 = v7 >> 1 >= 0x369D03 ? 0x7FFFFFFF : 600 * (v7 >> 1);
          if ( v17 < v18 )
            goto LABEL_15;
        }
      }
    }
    if ( !MiUseLowIoPriorityForModifiedPages(result) )
      v12 = -1;
    result = (_DWORD *)MiWakeModifiedPageWriter(v6, v12);
    v10 = a2;
    v3[1] = 0;
    goto LABEL_28;
  }
LABEL_15:
  v3[2] = v10;
  if ( (a3 & 7) == 0 )
  {
    v19 = v6[899];
    __dmb(0xBu);
    if ( v19 )
    {
      v20 = v6;
      do
      {
        v21 = v20[900];
        if ( (*(_WORD *)(v21 + 96) & 0x40) == 0 )
        {
          KeAcquireInStackQueuedSpinLock(v21 + 116, v23);
          if ( *(_DWORD *)(v21 + 84) != *(_DWORD *)(v21 + 80) )
            *(_DWORD *)(v21 + 76) = dword_681270;
          *(_DWORD *)(v21 + 88) = 4 * dword_681270;
          result = (_DWORD *)KeReleaseInStackQueuedSpinLock(v23);
        }
        ++v20;
        --v19;
      }
      while ( v19 );
    }
    if ( (v3[11] & 1) != 0 )
      return (_DWORD *)sub_517030();
  }
  if ( v6[168] )
    result = (_DWORD *)MiStoreUpdateMemoryConditions(v6);
  return result;
}
