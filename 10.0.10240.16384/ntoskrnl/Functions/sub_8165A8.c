// sub_8165A8 
 
void __fastcall sub_8165A8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, unsigned __int16 *a17, int a18, int a19, int a20, int *a21, int a22, int a23, int a24, int *a25, int a26, int a27, int a28, int *a29, int a30, int a31, int a32, int *a33, int a34, int a35, int a36, int *a37, int a38, int a39, int a40, int *a41, int a42, int a43, int a44, int *a45, int a46, int a47, int a48, int *a49, int a50, int a51, int a52)
{
  int v52; // r9
  int *v53; // r2
  int *v54; // r10
  int v55; // r5
  int *v56; // r6
  __int64 v57; // r0
  int v58; // r1
  int v59; // r1
  int v60; // r1
  int *v61; // r2
  int v62; // [sp+8h] [bp+8h]
  int v63; // [sp+Ch] [bp+Ch]
  int *v64; // [sp+10h] [bp+10h]

  if ( v52 )
    v53 = PPM_ETW_PROCESSOR_PROFILE_RUNDOWN;
  else
    v53 = PPM_ETW_PROCESSOR_PROFILE_REGISTERED;
  if ( EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)v53) )
  {
    v54 = &PpmDefaultProfile;
    v55 = 0;
    v56 = PpmCurrentProfile;
    v64 = PpmCurrentProfile;
    LODWORD(v57) = KeQueryInterruptTime();
    v62 = HIDWORD(v57);
    v63 = v57;
    PpmEndProfileAccumulation((int)v56, v57);
    while ( 1 )
    {
      RtlStringCchLengthW((unsigned __int16 *)*v54, 0x7FFFFFFFu, &a10);
      a17 = (unsigned __int16 *)*v54;
      a18 = 0;
      a19 = 2 * (a10 + 1);
      a20 = 0;
      a21 = v54 + 1;
      a22 = 0;
      a23 = 1;
      a24 = 0;
      a25 = v54 + 7;
      a26 = 0;
      a27 = 1;
      a28 = 0;
      a29 = v54 + 6;
      a30 = 0;
      a31 = 4;
      a32 = 0;
      a33 = v54 + 2;
      a34 = 0;
      a35 = 16;
      a36 = 0;
      a11 = _rt_udiv64(10i64, *((_QWORD *)v54 + 50));
      a12 = v58;
      a15 = _rt_udiv64(10i64, *((_QWORD *)v54 + 51));
      a16 = v59;
      a13 = _rt_udiv64(10i64, *((_QWORD *)v54 + 52));
      a14 = v60;
      a37 = v54 + 98;
      a38 = 0;
      a39 = 8;
      a40 = 0;
      a41 = &a11;
      a42 = 0;
      a43 = 8;
      a44 = 0;
      a45 = &a15;
      a46 = 0;
      a47 = 8;
      a48 = 0;
      a49 = &a13;
      a50 = 0;
      a51 = 8;
      a52 = 0;
      v61 = v52 ? PPM_ETW_PROCESSOR_PROFILE_RUNDOWN : PPM_ETW_PROCESSOR_PROFILE_REGISTERED;
      EtwWrite(PpmEtwHandle, dword_61DEC4, (int)v61, 0);
      if ( v55 == (unsigned __int8)PpmProfileCount )
        break;
      v54 = (int *)(PpmProfiles + 424 * v55);
      v55 = (unsigned __int8)(v55 + 1);
    }
    v64[96] = v63;
    v64[97] = v62;
  }
  JUMPOUT(0x7AD822);
}
