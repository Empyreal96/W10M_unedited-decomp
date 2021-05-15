// sub_7EEDD0 
 
void __fastcall sub_7EEDD0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
  unsigned int v16; // r2
  unsigned int v17; // r2
  void **v18; // r8
  int v19; // r2
  int v20; // r4
  unsigned int *v21; // r2
  unsigned int v22; // r0
  unsigned int v23; // r0
  unsigned int *v24; // r4
  unsigned int *v25; // r5
  int v26; // r6
  int v27; // r9
  __int64 v28; // r2
  int v29; // r1
  __int64 v30; // r2
  int v31; // r1
  unsigned int *v32; // r2
  unsigned int v33; // r1
  unsigned int *v34; // r2
  unsigned int v35; // r1
  unsigned int v36; // r2
  unsigned int v37; // r7
  unsigned int *v38; // r2
  int v39; // r3
  unsigned int v40; // r1
  unsigned int v41; // r0
  unsigned int *v42; // r2
  unsigned int v43; // r5
  unsigned int *v44; // r5
  unsigned int v45; // r4
  unsigned int v46; // r2
  int v47; // lr
  unsigned int v48; // [sp+4h] [bp+4h]

  while ( 1 )
  {
    v28 = *(_QWORD *)(v26 + 48);
    if ( (_DWORD)v28 == HIDWORD(v28) )
      break;
    v29 = *(_DWORD *)v28;
    *(_DWORD *)v28 = **(_DWORD **)v28;
    if ( v29 == *(_DWORD *)(v26 + 52) )
      *(_DWORD *)(v26 + 52) = *(_DWORD *)(v26 + 48);
    if ( v29 == 32 )
      break;
    __dmb(0xBu);
    do
      v16 = __ldrex(v24);
    while ( __strex(v16 - 1, v24) );
    __dmb(0xBu);
    do
      v17 = __ldrex(v25);
    while ( __strex(v17 - 1, v25) );
    __dmb(0xBu);
    ++v27;
    ExFreePoolWithTag(v29 - 32);
  }
  while ( 1 )
  {
    v30 = *(_QWORD *)(v26 + 60);
    if ( (_DWORD)v30 == HIDWORD(v30) )
      break;
    v31 = *(_DWORD *)v30;
    *(_DWORD *)v30 = **(_DWORD **)v30;
    if ( v31 == *(_DWORD *)(v26 + 64) )
      *(_DWORD *)(v26 + 64) = *(_DWORD *)(v26 + 60);
    v23 = v31 - 32;
    if ( v31 == 32 )
      break;
    __dmb(0xBu);
    v32 = (unsigned int *)(v26 + 160);
    do
      v33 = __ldrex(v32);
    while ( __strex(v33 - 1, v32) );
    __dmb(0xBu);
    v34 = (unsigned int *)(v26 + 156);
    do
      v35 = __ldrex(v34);
    while ( __strex(v35 - 1, v34) );
    __dmb(0xBu);
    ++v27;
    ExFreePoolWithTag(v23);
  }
  v36 = KeNumberProcessors_0;
  if ( (*(_DWORD *)(v26 + 12) & 0x10000000) != 0 )
  {
    v48 = 1;
    v37 = 0;
  }
  else
  {
    v37 = 0;
    v48 = KeNumberProcessors_0;
    if ( !KeNumberProcessors_0 )
      goto LABEL_41;
  }
  v47 = a5;
  v18 = &KiProcessorBlock;
  while ( 1 )
  {
    if ( (*(_DWORD *)(v26 + 12) & 0x10000000) != 0 )
    {
      v38 = (unsigned int *)(v26 + 88);
    }
    else
    {
      v39 = (int)(v37 >= v36 ? 0 : *v18);
      v38 = (unsigned int *)(*(_DWORD *)(v39 + 3596) + 4 * (v47 + 32));
    }
    __dmb(0xBu);
    do
      v40 = __ldrex(v38);
    while ( __strex(0, v38) );
    __dmb(0xBu);
    v41 = v40 & 0xFFFFFFF8;
    if ( (v40 & 0xFFFFFFF8) != 0 )
    {
      __dmb(0xBu);
      v42 = (unsigned int *)(v41 + 12);
      do
        v43 = __ldrex(v42);
      while ( __strex(v43 - (v40 & 7), v42) );
      __dmb(0xBu);
      v44 = (unsigned int *)(v26 + 160);
      do
      {
        v45 = *(_DWORD *)(v41 + 32);
        __dmb(0xBu);
        do
          v46 = __ldrex(v44);
        while ( __strex(v46 - 1, v44) );
        __dmb(0xBu);
        ++v27;
        ExFreePoolWithTag(v41);
        v41 = v45;
      }
      while ( v45 );
      v47 = a5;
    }
    ++v37;
    ++v18;
    if ( v37 >= v48 )
      break;
    v36 = KeNumberProcessors_0;
  }
LABEL_41:
  v19 = *(_DWORD *)(v26 + 224) & 1;
  __dmb(0xBu);
  v20 = -(*(_DWORD *)(v26 + 4) * v27);
  v21 = (unsigned int *)&dword_61AD64[v19];
  do
    v22 = __ldrex(v21);
  while ( __strex(v22 + v20, v21) );
  __dmb(0xBu);
  __asm { POP.W           {R1-R11,PC} }
}
