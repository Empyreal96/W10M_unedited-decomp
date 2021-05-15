// sub_51E950 
 
void __fastcall sub_51E950(int a1, int a2, int a3, int a4, _DWORD *a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38)
{
  int *v38; // r7
  int v39; // r8
  int v40; // r9
  void **v41; // r10
  unsigned int v42; // lr
  _DWORD *v43; // r1
  unsigned int *v44; // lr
  unsigned int v45; // r2
  int *v46; // r4
  int *v47; // r2
  int v48; // r3
  _DWORD *v49; // [sp+0h] [bp+0h]
  unsigned int *v50; // [sp+4h] [bp+4h]
  _BYTE *v51; // [sp+8h] [bp+8h]
  int v52; // [sp+10h] [bp+10h]
  int v53; // [sp+20h] [bp+20h]

  v53 = *v38;
  v52 = *v38;
  v42 = HIWORD(*v38);
  if ( v42 >= 0x20 )
    v42 = (unsigned __int16)(HIWORD(v53) - 32);
  if ( (unsigned __int8)v53 == 26 && (v51 = v41[v42], v51[1752]) )
    v43 = &v51[a3];
  else
    v43 = (char *)v41[v42] + a2;
  v44 = v43 + 2;
  v49 = v43;
  v50 = v43 + 2;
  if ( ((unsigned int)v41[545] & v40) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)(v43 + 2));
  }
  else
  {
    do
      v45 = __ldrex(v44);
    while ( __strex(1u, v44) );
    __dmb(0xBu);
    v41 = &KiProcessorBlock;
    if ( !v45 )
    {
LABEL_13:
      if ( v39 == v38[7] && v52 == *v38 )
      {
        v46 = v38 + 1;
        v47 = v43;
        --v43[3];
        if ( (int *)*v43 != v38 + 1 )
        {
          do
            v47 = (int *)*v47;
          while ( (int *)*v47 != v46 );
        }
        v48 = *v46;
        *v47 = *v46;
        if ( !v48 )
          v43[1] = v47;
        v38[7] = 0;
      }
      if ( ((unsigned int)v41[545] & a1) != 0 )
      {
        KiReleaseSpinLockInstrumented(v44, a38);
      }
      else
      {
        __dmb(0xBu);
        *v44 = 0;
      }
      JUMPOUT(0x44DDB0);
    }
    KxWaitForSpinLockAndAcquire(v43 + 2);
  }
  v43 = v49;
  v44 = v50;
  a1 = v40 - 0x200000;
  goto LABEL_13;
}
