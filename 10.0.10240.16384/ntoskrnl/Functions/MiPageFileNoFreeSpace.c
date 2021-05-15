// MiPageFileNoFreeSpace 
 
unsigned int __fastcall MiPageFileNoFreeSpace(int a1, _DWORD *a2, int a3, int a4)
{
  _DWORD *v4; // r4
  int v7; // r7
  _DWORD *v8; // r1
  unsigned int result; // r0
  unsigned int v10; // r1
  int v11; // r1
  unsigned int v12; // r6
  unsigned int v13; // r2
  _DWORD *v14; // r5
  int v15; // r7
  __int16 v16; // r3
  unsigned int v17; // r3
  _DWORD v18[8]; // [sp+0h] [bp-20h] BYREF

  v18[0] = a2;
  v18[1] = a3;
  v18[2] = a4;
  v4 = *(_DWORD **)(a1 + 128);
  MiFreeModifiedReservations(a1);
  v7 = 0;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 116), (unsigned int)v18);
  if ( *(_DWORD *)(a1 + 12) )
  {
    v8 = (_DWORD *)v4[135];
    *a2 = v4 + 134;
    a2[1] = v8;
    if ( (_DWORD *)*v8 != v4 + 134 )
      __fastfail(3u);
    *v8 = a2;
    v4[135] = a2;
  }
  else
  {
    v7 = 1;
    *(_BYTE *)(a1 + 98) |= 1u;
  }
  result = KeReleaseInStackQueuedSpinLock((int)v18);
  if ( v7 == 1 )
  {
    *a2 = -1719109871;
    result = v4[961];
    v10 = v4[1029];
    if ( result > v10 )
      result = v4[1029];
    if ( (*(_WORD *)(a1 + 96) & 0x10) == 0 )
    {
      if ( result > 8 * (v10 / 0xA) && v10 < v4[801] )
      {
        result = MiCauseOverCommitPopup((int)v4);
        v11 = 1;
LABEL_23:
        if ( v4[1029] < v4[801] )
          result = MiIssuePageExtendRequestNoWait((int)v4, v11, 1);
        return result;
      }
      if ( v4[1030] >= 0x1000u )
      {
        v12 = v4[899];
        v13 = 0;
        __dmb(0xBu);
        result = 0;
        if ( v12 )
        {
          v14 = v4;
          do
          {
            v15 = v14[900];
            v16 = *(_WORD *)(v15 + 96);
            if ( (v16 & 0x10) == 0 && (v16 & 0x40) == 0 )
            {
              if ( *(_DWORD *)(v15 + 12) + v13 < v13 )
                break;
              v13 += *(_DWORD *)(v15 + 12);
            }
            ++result;
            ++v14;
          }
          while ( result < v12 );
        }
        v17 = v4[1030];
        if ( v17 > v13 )
        {
          v11 = v17 - v13;
          if ( v17 != v13 )
            goto LABEL_23;
        }
      }
    }
  }
  return result;
}
