// PopPepComponentSetResidency 
 
int __fastcall PopPepComponentSetResidency(int a1, int a2, unsigned __int64 a3)
{
  unsigned int v3; // r4
  unsigned int *v4; // r6
  unsigned int v5; // r5
  int v8; // r9
  int v9; // r0
  int v10; // r8
  int v11; // r5
  unsigned int v12; // r4
  int v13; // [sp+0h] [bp-28h]
  unsigned __int64 v14[4]; // [sp+8h] [bp-20h] BYREF

  v14[0] = a3;
  v3 = HIDWORD(a3);
  v4 = (unsigned int *)(a1 + 168 * a2);
  v5 = a3;
  if ( ((unsigned int)a3 & HIDWORD(a3)) == -1 )
    return sub_554368();
  v8 = PopPepComponentGetResidencyIdleState((int)(v4 + 32), a3);
  v9 = PopPepLockActivityLink(a1, v4 + 32, 6, 1u, v14);
  v4[56] = v5;
  v4[57] = v3;
  v4[54] = v5;
  v4[55] = v3;
  v10 = v9;
  if ( v4[64] != v8 )
  {
    v4[64] = v8;
    v11 = *(_DWORD *)(a1 + 72);
    v12 = v4[50];
    PopPepUpdateIdleState(a1, v4 + 32, 1);
    PopPepPromoteActivities(a1, (int)(v4 + 32), 2);
    PopPepRequestWork(v12 + v11, v4[50] + *(_DWORD *)(a1 + 72));
  }
  PopPepReleaseActivityLink(a1, v4 + 32, v10, LOBYTE(v14[0]));
  return v13;
}
