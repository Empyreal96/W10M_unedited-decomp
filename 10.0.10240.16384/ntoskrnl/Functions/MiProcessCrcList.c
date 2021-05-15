// MiProcessCrcList 
 
// local variable allocation has failed, the output may be wrong!
__int64 *__fastcall MiProcessCrcList(__int64 *result, unsigned int a2, unsigned int a3, int a4, int a5, int a6, _DWORD *a7)
{
  __int16 **v9; // r0
  unsigned __int16 v10; // r8
  __int16 *v11; // r10
  unsigned int i; // r4
  unsigned int v13; // r3
  _DWORD *v14; // r7
  int v15; // r10
  unsigned int v16; // r8
  int v17; // r0
  unsigned int v18; // r5
  int v19; // r2
  _DWORD *v20; // r1
  unsigned int v21; // r6
  _DWORD *v22; // r4
  int v23; // r0
  int v24; // r0
  unsigned int *v25; // r6
  int v26; // r7
  unsigned int v27; // r5
  __int64 v28; // kr00_8
  unsigned int v29; // r4
  __int16 *v30; // r0
  int j; // r4
  int v32; // r1 OVERLAPPED
  int v33; // r2 OVERLAPPED
  __int64 *v34[2]; // [sp+30h] [bp-88h] BYREF
  int v35[3]; // [sp+38h] [bp-80h] BYREF
  _DWORD *v36; // [sp+44h] [bp-74h]
  __int64 *v37; // [sp+48h] [bp-70h]
  int v38; // [sp+4Ch] [bp-6Ch]
  unsigned int v39; // [sp+50h] [bp-68h]
  __int16 *v40; // [sp+54h] [bp-64h]
  __int16 **v41[2]; // [sp+64h] [bp-54h] BYREF
  int v42; // [sp+70h] [bp-48h]
  _DWORD *v43; // [sp+74h] [bp-44h]
  _DWORD v44[4]; // [sp+78h] [bp-40h] BYREF
  _DWORD v45[12]; // [sp+88h] [bp-30h]

  v38 = a4;
  v42 = a5;
  v43 = a7;
  v44[0] = 0;
  v44[1] = 0;
  v44[2] = 0;
  v45[0] = 0;
  v45[1] = 0;
  v45[2] = 0;
  v37 = result;
  if ( a3 )
  {
    v40 = *(__int16 **)result;
    v36 = 0;
    v35[0] = 0;
    v41[0] = (__int16 **)result;
    qsort(a2, a3, 0x18u, (int (__fastcall *)(unsigned int, _BYTE *))MiCombinePageSortByHash);
    v9 = (__int16 **)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v34[1] = (__int64 *)v34;
    v34[0] = (__int64 *)v34;
    v39 = a2 + 24 * a3 - 24;
    v41[1] = v9;
    v35[1] = 0;
    v35[2] = 0;
    if ( a2 > v39 )
    {
      v10 = v38;
      v11 = v40;
      for ( i = 0; i < 3; ++i )
      {
        v13 = v45[i];
        if ( v13 )
        {
          if ( v13 > 0xFFFFE )
            v13 = 1048574;
          v44[i] = MiAllocatePagesForMdl(v11, 0i64, -1i64, 0i64, v13 << 12, i, v10, 19);
        }
      }
      v14 = v36;
      v15 = v38;
      if ( v36 )
      {
        do
        {
          RtlAvlRemoveNode((int)v35, (int)v14);
          v16 = v14[3];
          v17 = ExAllocatePoolWithTag(1, 8 * v16, 1834379597);
          v18 = v17;
          if ( v17 )
          {
            v19 = v14[6];
            if ( v19 )
            {
              v20 = (_DWORD *)v17;
              do
              {
                *v20 = *(_DWORD *)(v19 + 8);
                v20[1] = v19;
                v19 = *(_DWORD *)(v19 + 12);
                v20 += 2;
              }
              while ( v19 );
            }
            qsort(v17, v16, 8u, (int (__fastcall *)(unsigned int, _BYTE *))MiCombinePageSortByVa);
            v21 = 0;
            v14[6] = 0;
            if ( v16 )
            {
              v22 = (_DWORD *)v18;
              do
              {
                v23 = v22[1];
                if ( v21 && *v22 == *(v22 - 2) )
                {
                  MiDereferenceCombineCrc(v23);
                  --v14[3];
                }
                else
                {
                  *(_DWORD *)(v23 + 12) = v14[6];
                  v14[6] = v23;
                }
                ++v21;
                v22 += 2;
              }
              while ( v21 < v16 );
            }
            ExFreePoolWithTag(v18);
            MiSharePages(v14, v34, v41, v42, v15, (int)v44, v43);
          }
          else
          {
            for ( j = v14[6]; j; j = *(_DWORD *)(j + 12) )
              MiDereferenceCombineCrc(j);
          }
          v24 = v14[5];
          if ( v24 )
            ObfDereferenceObject(v24);
          ExFreePoolWithTag((unsigned int)v14);
          v14 = (_DWORD *)v35[0];
        }
        while ( v35[0] );
      }
      v25 = v44;
      v26 = 3;
      do
      {
        v27 = *v25;
        if ( *v25 )
        {
          v28 = *(_QWORD *)(v27 + 20);
          if ( HIDWORD(v28) != (_DWORD)v28 )
          {
            v29 = (unsigned int)(v28 - HIDWORD(v28)) >> 12;
            memmove(v27 + 28, v27 + 28 + 4 * (HIDWORD(v28) >> 12), 4 * v29);
            v30 = v40;
            *(_QWORD *)(v27 + 20) = v29 << 12;
            MiFreePagesFromMdl(v30, v27, 0);
          }
          ExFreePoolWithTag(v27);
          *v25 = 0;
        }
        ++v25;
        --v26;
      }
      while ( v26 );
      while ( 1 )
      {
        result = v34[0];
        if ( (__int64 **)v34[0] == v34 )
          break;
        *(_QWORD *)&v32 = *v34[0];
        if ( *((__int64 ***)v34[0] + 1) != v34 || *(__int64 **)(v32 + 4) != v34[0] )
          __fastfail(3u);
        v34[0] = (__int64 *)v32;
        *(_DWORD *)(v32 + 4) = v34;
        *((_DWORD *)result + 6) = 0;
        MiFreeCombineBlock((int)result, v32, v33, (int)v34);
      }
    }
    else
    {
      if ( !a6 )
        JUMPOUT(0x80FC8C);
      result = (__int64 *)sub_80FC84();
    }
  }
  return result;
}
