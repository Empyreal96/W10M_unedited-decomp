// PopPepDeviceDState 
 
int __fastcall PopPepDeviceDState(int result, int a2, int a3, int a4)
{
  int v5; // r8
  int v7; // r6
  unsigned int *v8; // r9
  unsigned int v9; // r5
  unsigned int *v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r1
  int v13; // r1
  int v14; // r9
  int v15; // r2
  int v16; // r10
  int v17; // r2
  unsigned int v18; // r5
  _DWORD *v19; // r4
  _DWORD *v20; // r5
  unsigned int v21; // r8
  int v22; // r4
  unsigned int v23; // r5
  int v24; // r4
  int v25; // [sp+0h] [bp-30h]
  char v26; // [sp+4h] [bp-2Ch]
  int v27[2]; // [sp+8h] [bp-28h] BYREF
  char v28; // [sp+10h] [bp-20h]
  char v29; // [sp+11h] [bp-1Fh]

  v25 = a3;
  v26 = a4;
  v5 = a3;
  v7 = result;
  if ( a3 )
  {
    if ( a2 == 1 )
    {
      __dmb(0xBu);
      v10 = (unsigned int *)(result + 84);
      do
      {
        v11 = __ldrex(v10);
        v12 = v11 - 1;
      }
      while ( __strex(v12, v10) );
      __dmb(0xBu);
      if ( !v12 )
        result = PopPepUpdateConstraints(result, 4, 1);
    }
  }
  else if ( a2 > 1 )
  {
    __dmb(0xBu);
    v8 = (unsigned int *)(result + 84);
    do
      v9 = __ldrex(v8);
    while ( __strex(2u, v8) );
    __dmb(0xBu);
    result = PopPepUpdateConstraints(result, 4, 0);
    if ( a4 )
      return sub_54B1D8(result);
  }
  if ( *(_BYTE *)(v7 + 76) )
  {
    v13 = v7 + 96;
    if ( a2 == 4 )
      v14 = 0;
    else
      v14 = *(_DWORD *)(v13 + 4 * a2 - 4);
    v15 = *(_DWORD *)(v7 + 108);
    if ( v15 == 4 )
      v16 = 0;
    else
      v16 = *(_DWORD *)(v13 + 4 * v15 - 4);
    if ( !v5 && v15 != a2 )
    {
      if ( a2 == 1 && *(_DWORD *)(v7 + 120) )
      {
        v20 = (_DWORD *)(v7 + 128);
        v21 = 0;
        do
        {
          v22 = v20[36];
          PopPepUpdateIdleStateRefCount(0, *(_DWORD *)(v20[40] + 24 * v22 + 16), 1);
          PopFxUpdateComponentAccountingEnhanced(*(_DWORD *)(v7 + 24), v20[2], v22, 0);
          ++v21;
          v20 += 42;
        }
        while ( v21 < *(_DWORD *)(v7 + 120) );
        v5 = v25;
      }
      PopPepUpdateIdleStateRefCount(v16, v14, 1);
      PopFxUpdateDeviceAccountingEnhanced(*(_DWORD *)(v7 + 24), a2, 0);
    }
    v17 = *(_DWORD *)(v7 + 24);
    v27[1] = a2;
    v28 = v5;
    v27[0] = *(_DWORD *)(v17 + 40);
    v29 = v26;
    result = (*(int (__fastcall **)(int, int *))(*(_DWORD *)(v17 + 36) + 64))(5, v27);
    if ( v5 && *(_DWORD *)(v7 + 108) != a2 )
    {
      if ( PopFxPerfQueryOnDevicePowerChanges && (*(_BYTE *)(v7 + 117) || *(_BYTE *)(v7 + 116) && a2 == 1) )
      {
        v23 = 0;
        if ( *(_DWORD *)(v7 + 120) )
        {
          v24 = v7 + 128;
          do
          {
            if ( *(_BYTE *)(v24 + 152) )
              PopFxUpdateComponentPerfStateNominalChange(*(_DWORD *)(v7 + 24), *(_DWORD *)(v24 + 8), 1, a2);
            ++v23;
            v24 += 168;
          }
          while ( v23 < *(_DWORD *)(v7 + 120) );
        }
      }
      if ( *(_DWORD *)(v7 + 108) == 1 )
      {
        v18 = 0;
        if ( *(_DWORD *)(v7 + 120) )
        {
          v19 = (_DWORD *)(v7 + 128);
          do
          {
            PopPepUpdateIdleStateRefCount(*(_DWORD *)(v19[40] + 24 * v19[36] + 16), 0, 0);
            PopFxUpdateComponentAccountingEnhanced(*(_DWORD *)(v7 + 24), v19[2], v19[39] - 1, 1);
            ++v18;
            v19 += 42;
          }
          while ( v18 < *(_DWORD *)(v7 + 120) );
        }
      }
      PopPepUpdateIdleStateRefCount(v16, v14, 0);
      result = PopFxUpdateDeviceAccountingEnhanced(*(_DWORD *)(v7 + 24), a2, 1);
      *(_DWORD *)(v7 + 108) = a2;
    }
  }
  return result;
}
