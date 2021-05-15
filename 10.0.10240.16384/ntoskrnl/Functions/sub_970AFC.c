// sub_970AFC 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_970AFC(int a1, int a2, int a3, int a4, __int64 a5, __int64 a6, unsigned int a7, unsigned __int64 a8, int a9, int a10, unsigned __int64 a11, int a12, int a13, __int16 a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, int a45, int a46, int a47, int a48, int a49, int a50, int a51, int a52, int a53, int a54, int a55, int a56, int a57, int a58, int a59, int a60)
{
  __int64 *v60; // r4
  int v61; // r7
  int v62; // r5 OVERLAPPED
  int v63; // r3
  __int64 v64; // r2
  unsigned int v65; // kr00_4
  unsigned int v66; // r6
  unsigned int v67; // lr
  unsigned int v68; // r0
  unsigned int v69; // r8
  unsigned int v70; // r10
  unsigned int v71; // r9
  int v72; // lr
  int v73; // r6 OVERLAPPED
  int v74; // r2
  __int64 v75; // kr28_8
  int v76; // r3
  int v77; // r2
  int v78; // r2

  if ( RtlQueryDynamicTimeZoneInformation((int)&a18) >= 0 )
  {
    v61 = a60 + a18;
    v62 = a39 + a18;
    RtlTimeToTimeFields((int)v60, &a14, a18, a39);
    if ( HIWORD(a35) )
    {
      if ( HIWORD(a56)
        && RtlCutoverTimeToSystemTime(&a35, &a5, (int)v60, SHIWORD(a56))
        && RtlCutoverTimeToSystemTime(&a56, &a6, (int)v60, v63) )
      {
        LODWORD(v64) = 60 * v62 * (_DWORD)dword_989680;
        HIDWORD(v64) = HIDWORD(a6);
        v65 = a6;
        LODWORD(a6) = v64 + a6;
        v67 = (v64 + __PAIR64__((unsigned __int64)(60 * v62 * (__int64)(int)dword_989680) >> 32, v65)) >> 32;
        v66 = v64 + v65;
        LODWORD(v64) = 60 * v61 * (_DWORD)dword_989680;
        HIDWORD(a6) = v67;
        a7 = v67;
        HIDWORD(v64) = HIDWORD(a5);
        a5 = v64 + __PAIR64__((unsigned __int64)(60 * v61 * (__int64)(int)dword_989680) >> 32, a5);
        v69 = HIDWORD(a5);
        v68 = a5;
        if ( __SPAIR64__(v67, v66) >= a5 )
        {
          v70 = a5;
          a8 = a5;
          v71 = HIDWORD(a5);
          v74 = v62;
          a9 = v62;
          v68 = v66;
          a11 = __PAIR64__(a7, v66);
          v69 = a7;
          v72 = 1;
          v62 = v61;
          a12 = v61;
          v73 = 2;
        }
        else
        {
          v70 = v66;
          a8 = __PAIR64__(v67, v66);
          v71 = v67;
          v72 = 2;
          v73 = 1;
          v74 = v61;
          a9 = v61;
          a11 = a5;
          a12 = v62;
        }
        v75 = *v60;
        a13 = v73;
        a10 = v72;
        if ( v75 < __SPAIR64__(v71, v70) || v75 >= __SPAIR64__(v69, v68) )
        {
          *(_QWORD *)&ExpLastTimeZoneBias = *(_QWORD *)&v62;
          v76 = 15 * v62;
        }
        else
        {
          ExpLastTimeZoneBias = v74;
          ExpCurrentTimeZoneId = v72;
          v76 = 15 * v74;
        }
        ExpTimeZoneBias = 4 * v76 * (__int64)(int)dword_989680;
        MEMORY[0xFFFF925C] = 0;
        __dmb(0xBu);
        MEMORY[0xFFFF9028] = (unsigned __int64)(4 * v76 * (__int64)(int)dword_989680) >> 32;
        v77 = ExpTimeZoneBias;
        __dmb(0xBu);
        MEMORY[0xFFFF9020] = v77;
        v78 = HIDWORD(ExpTimeZoneBias);
        __dmb(0xBu);
        MEMORY[0xFFFF9024] = v78;
      }
    }
  }
  JUMPOUT(0x964F00);
}
