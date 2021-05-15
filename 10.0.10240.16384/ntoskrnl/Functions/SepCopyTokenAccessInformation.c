// SepCopyTokenAccessInformation 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall SepCopyTokenAccessInformation(_DWORD *a1, _DWORD *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, char a14, int a15)
{
  char *v16; // r10
  int v19; // r2
  int v20; // r3
  int v21; // r3
  _QWORD *v22; // r6
  _QWORD *v23; // r4 OVERLAPPED
  _DWORD *v25; // r4
  _DWORD *v26; // r5
  int v27; // r0
  int v28; // r4
  int v29; // r5
  int v30; // r1
  int v31; // r4
  int v32; // r5
  int v33; // r4
  char *v34; // [sp+0h] [bp-30h]
  char v35[32]; // [sp+10h] [bp-20h] BYREF

  v16 = (char *)a2 + a3;
  a2[3] = a1[6];
  a2[4] = a1[7];
  a2[5] = a1[42];
  a2[6] = a1[43];
  a2[8] = a1[44];
  SeQueryMandatoryPolicyToken((int)a1, a2 + 7);
  v19 = a1[157];
  if ( v19 )
    v20 = *(_DWORD *)(v19 + 20);
  else
    v20 = 0;
  a2[9] = v20;
  a2[14] = a1[31];
  a2[15] = a2 + 48;
  *a2 = a2 + 14;
  v34 = (char *)a2 + a6 + 192;
  RtlCopySidAndAttributesArray(a1[31], a1[37]);
  RtlSidHashInitialize(a2 + 48, a1[31], (int)(a2 + 14));
  v21 = a1[32];
  v22 = (_QWORD *)((char *)a2 + a5 + 192);
  v23 = v22 + 17;
  *v22 = *(_QWORD *)(&v23 - 1);
  a2[1] = v22;
  if ( a1[32] )
    return sub_7E5B20();
  v25 = (_DWORD *)((char *)v23 + a7);
  v26 = v25 + 34;
  *v25 = a1[122];
  v25[1] = v25 + 34;
  a2[11] = v25;
  v27 = a1[122];
  if ( v27 )
  {
    v34 = (char *)v26 + a11;
    RtlCopySidAndAttributesArray(v27, a1[121]);
    RtlSidHashInitialize(v25 + 34, a1[122], (int)v25);
  }
  v28 = (int)v26 + a10;
  v29 = 0;
  if ( a9 )
  {
    v29 = v28;
    memmove(v28, a1[120], 4 * (*(unsigned __int8 *)(a1[120] + 1) + 2));
  }
  a2[10] = v29;
  if ( a14 )
    v30 = a15;
  else
    v30 = a1[160];
  v31 = v28 + a9;
  v32 = 0;
  if ( a12 )
  {
    v32 = v31;
    memmove(v31, v30, 4 * (*(unsigned __int8 *)(v30 + 1) + 2));
  }
  a2[12] = v32;
  v33 = v31 + a12;
  AuthzBasepQueryInternalSecurityAttributesToken(a1[119], v33, &v16[-v33], v35, v34, v35, v35);
  a2[13] = v33;
  *(_DWORD *)(a13 + v33) = a4;
  a2[2] = a13 + v33;
  return SepConvertTokenPrivilegesToLuidAndAttributes(a1, a13 + v33 + 4);
}
