// ObCheckCreateObjectAccess 
 
int __fastcall ObCheckCreateObjectAccess(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21)
{
  int v23; // r6
  int v24; // r0
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28; // r5
  int v29; // r0
  int v30; // r6
  int v31; // r4
  char v33[4]; // [sp+18h] [bp-28h] BYREF
  int v34; // [sp+1Ch] [bp-24h] BYREF
  int v35; // [sp+20h] [bp-20h] BYREF
  int v36[7]; // [sp+24h] [bp-1Ch] BYREF

  v36[0] = 0;
  v34 = 0;
  v23 = ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
  v24 = ObpGetObjectSecurity(a1, &v35, v33, (char)a6);
  if ( v24 < 0 )
    return sub_7C4F0C(
             v24,
             v25,
             v26,
             v27,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             a14,
             a15,
             a16,
             a17,
             a18,
             a19,
             a20,
             a21);
  SeLockSubjectContext(a3 + 28);
  v28 = v35;
  if ( v35 )
  {
    v29 = SeAccessCheck(v35, a3 + 28, 1, a2, 0, (int)&v34, v23 + 52, a6, (int)v36, a7);
    v30 = v34;
    v31 = v29;
    if ( v34 )
    {
      SeAppendPrivileges(a3, v34);
      ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v30);
    }
  }
  else
  {
    v31 = 1;
  }
  SeUnlockSubjectContext(a3 + 28);
  ObReleaseObjectSecurity(v28, (unsigned __int8)v33[0]);
  return v31;
}
