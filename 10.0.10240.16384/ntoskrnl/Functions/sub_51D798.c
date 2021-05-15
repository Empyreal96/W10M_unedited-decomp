// sub_51D798 
 
void __fastcall sub_51D798(int a1, int a2, int a3, int a4, __int16 a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, char a16, int *a17)
{
  _DWORD *v17; // r4
  int v18; // r5
  int v19; // r8
  int v20; // r9
  int v21; // r10
  unsigned int v22; // r2
  int v23; // r6
  int v24; // r2
  int v25; // r0
  unsigned int v26; // r1
  int v27; // r3

  v20 = *(_DWORD *)(a1 + 4);
  v21 = a1 + 8;
  if ( a1 == -8 )
    JUMPOUT(0x44B02A);
  if ( a16 )
  {
    if ( v18 )
    {
      v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v22 + 308);
      ExAcquireResourceSharedLite(*(_DWORD *)(v18 + 48), 1);
    }
    else
    {
      SeLockSubjectContext(v17);
    }
    v19 = 1;
  }
  if ( v18 )
  {
    v23 = a15;
  }
  else
  {
    if ( !*v17 )
      goto LABEL_12;
    v23 = *(_DWORD *)(*v17 + 640);
    if ( RtlSidDominatesForTrust(*(_DWORD *)(v17[2] + 640), v23, &a5) < 0 )
      goto LABEL_18;
    if ( !(_BYTE)a5 )
LABEL_12:
      v23 = *(_DWORD *)(v17[2] + 640);
  }
  if ( RtlSidDominatesForTrust(v23, v21, (_BYTE *)&a5 + 1) >= 0 )
  {
    if ( HIBYTE(a5) )
      v24 = -1;
    else
      v24 = v20 | 0x1000000;
    *a17 = v24;
  }
LABEL_18:
  if ( v19 )
  {
    if ( v18 )
    {
      v25 = ExpReleaseResourceForThreadLite(*(_DWORD *)(v18 + 48), __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
      v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v27 = (__int16)(*(_WORD *)(v26 + 0x134) + 1);
      *(_WORD *)(v26 + 308) = v27;
      if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
        KiCheckForKernelApcDelivery(v25);
    }
    else
    {
      SeUnlockSubjectContext(v17);
    }
  }
  JUMPOUT(0x44B032);
}
