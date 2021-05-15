// RtlAddAtomToAtomTableEx 
 
int __fastcall RtlAddAtomToAtomTableEx(int a1, _WORD *a2, _WORD *a3, int a4)
{
  int v8; // r4
  __int16 v9; // r3
  int *v10; // r10
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r3
  int v14; // r0
  unsigned int v16; // [sp+10h] [bp-30h] BYREF
  int v17; // [sp+14h] [bp-2Ch]
  int v18; // [sp+18h] [bp-28h] BYREF
  int v19; // [sp+1Ch] [bp-24h] BYREF
  _DWORD _20[14]; // [sp+20h] [bp-20h] BYREF

  _20[11] = a2;
  _20[12] = a3;
  _20[13] = a4;
  _20[10] = a1;
  if ( RtlpLockAtomTable() )
  {
    if ( RtlGetIntegerAtom(a2, &v16) )
    {
      v9 = v16;
      if ( (unsigned __int16)v16 < 0xC000u )
      {
        v8 = 0;
      }
      else
      {
        v9 = 0;
        LOWORD(v16) = 0;
        v8 = -1073741811;
      }
      v17 = v8;
      if ( a3 )
        *a3 = v9;
      goto LABEL_28;
    }
    if ( *a2 )
    {
      v8 = RtlpHashStringToAtom(a1, a2, 0, _20, &v16, &v18, &v19);
      v17 = v8;
      if ( v8 < 0 )
      {
LABEL_28:
        RtlpUnlockAtomTable(a1);
        return v8;
      }
      if ( v19 )
      {
        v14 = RtlpReferenceAtom(v19, v18);
        if ( a3 )
          *a3 = *(_WORD *)(v14 + 6);
        v8 = 0;
      }
      else
      {
        v10 = (int *)_20[0];
        if ( _20[0] )
        {
          v8 = -1073741801;
          v17 = -1073741801;
          v11 = RtlpAllocateAtomTableEntry(v16, &v18, a4);
          v12 = v11;
          v19 = v11;
          if ( v11 )
          {
            memmove(v11 + 26, (int)a2, v16);
            v13 = v16 >> 1;
            *(_BYTE *)(v12 + 24) = v16 >> 1;
            *(_WORD *)(v12 + 2 * ((unsigned __int8)v13 + 13)) = 0;
            if ( RtlpInsertStringAtom(a1, v12) )
            {
              *(_WORD *)(v12 + 6) = *(_WORD *)(v12 + 4) | 0xC000;
              *v10 = v12;
              if ( a3 )
                *a3 = *(_WORD *)(v12 + 6);
              v8 = 0;
              v17 = 0;
            }
            else
            {
              if ( v18 && v18 != v12 + 8 )
                RtlpFreeAtom(v18);
              RtlpFreeAtom(v12);
            }
          }
          goto LABEL_28;
        }
        v8 = -1073741811;
      }
    }
    else
    {
      v8 = -1073741773;
    }
    v17 = v8;
    goto LABEL_28;
  }
  return -1073741811;
}
