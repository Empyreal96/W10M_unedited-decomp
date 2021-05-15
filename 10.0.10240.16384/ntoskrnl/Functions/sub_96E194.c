// sub_96E194 
 
void __fastcall sub_96E194(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, unsigned int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, unsigned int a31, unsigned int a32)
{
  unsigned int v32; // r5
  unsigned int v33; // r6
  unsigned int v34; // r8
  int v35; // r0
  unsigned int v36; // r6
  int v37; // r7
  int v38; // r0
  unsigned int v39; // r5
  unsigned int v40; // r6
  unsigned int v41; // r9
  unsigned int v42; // r2
  unsigned int v43; // r3
  unsigned int v44; // r2
  unsigned int v45; // r2
  int v46; // r3
  __int16 v47; // r3
  unsigned int v48; // r0
  int v49; // [sp+Ch] [bp+Ch]
  unsigned int v50; // [sp+10h] [bp+10h]
  int v51; // [sp+14h] [bp+14h]

  if ( ZwQueryKey() >= 0 && a31 && a32 && a32 <= 0xFFFF )
  {
    v32 = 0;
    v33 = 0;
    v34 = 0;
    do
    {
      v35 = ZwEnumerateValueKey();
      if ( v35 < 0 && v35 != -2147483643 )
        goto LABEL_43;
      if ( a20 == 4 && a21 >= 2 )
      {
        v32 += a21 + 8;
        if ( v32 < a21 + 8 )
          goto LABEL_43;
        ++v34;
      }
      ++v33;
    }
    while ( v33 < a31 );
    if ( !v34 )
      JUMPOUT(0x95F77C);
    v36 = v32 + 8;
    if ( v32 + 8 >= v32 )
    {
      v37 = ExAllocatePoolWithTag(1, a32 + 16, 1668499779);
      if ( v37 )
      {
        v38 = ExAllocatePoolWithTag(1, v32 + 8, 1668499779);
        v39 = v38;
        if ( v38 )
        {
          *(_WORD *)(v38 + 6) = 0;
          v49 = v38 + 8 * (v34 + 1);
          v50 = v36 - 8 * (v34 + 1);
          *(_WORD *)(v38 + 4) = -1;
          v40 = 0;
          v41 = 0;
          v51 = v38;
          do
          {
            if ( ZwEnumerateValueKey() < 0 )
              goto LABEL_39;
            if ( *(_DWORD *)(v37 + 4) == 4 && *(_DWORD *)(v37 + 8) >= 2u )
            {
              do
              {
                v42 = *(_DWORD *)(v37 + 8);
                if ( *(_WORD *)(v37 + 2 * (v42 >> 1) + 10) )
                  break;
                *(_DWORD *)(v37 + 8) = v42 - 2;
              }
              while ( v42 - 2 >= 2 );
              v43 = *(_DWORD *)(v37 + 8);
              if ( v43 )
              {
                if ( v43 > v50 || v41 >= v34 )
                  goto LABEL_39;
                v44 = *(unsigned __int16 *)(v39 + 4);
                if ( v44 >= v43 )
                  v44 = *(_DWORD *)(v37 + 8);
                *(_WORD *)(v39 + 4) = v44;
                v45 = *(unsigned __int16 *)(v39 + 6);
                if ( v45 <= *(_DWORD *)(v37 + 8) )
                  v45 = *(_DWORD *)(v37 + 8);
                *(_WORD *)(v39 + 6) = v45;
                *(_DWORD *)(v51 + 12) = v49;
                *(_WORD *)(v51 + 8) = *(_DWORD *)(v37 + 8);
                *(_WORD *)(v51 + 10) = *(_DWORD *)(v37 + 8);
                memmove(v49, v37 + 12, *(_DWORD *)(v37 + 8));
                v46 = *(_DWORD *)(v37 + 8);
                ++v41;
                v49 += v46;
                v50 -= v46;
                v51 += 8;
              }
            }
            ++v40;
          }
          while ( v40 < a31 );
          v47 = *(_WORD *)(v39 + 4);
          *(_DWORD *)v39 = v41;
          *(_WORD *)(v39 + 4) = v47 + 8;
          *(_WORD *)(v39 + 6) += 8;
          __dmb(0xBu);
          do
            v48 = __ldrex((unsigned int *)&dword_64A164);
          while ( !v48 && __strex(v39, (unsigned int *)&dword_64A164) );
          __dmb(0xBu);
          if ( !v48 )
            v39 = 0;
LABEL_39:
          if ( v39 )
            ExFreePoolWithTag(v39);
        }
        ExFreePoolWithTag(v37);
      }
    }
  }
LABEL_43:
  JUMPOUT(0x95F77E);
}
