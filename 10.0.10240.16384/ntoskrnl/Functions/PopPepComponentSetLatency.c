// PopPepComponentSetLatency 
 
int __fastcall PopPepComponentSetLatency(int a1, int a2, __int64 a3)
{
  int v3; // r6
  int v6; // r9
  int v7; // r0
  int v8; // r8
  int v9; // r5
  int v10; // r4
  int v12; // [sp+0h] [bp-28h]
  __int64 v13[4]; // [sp+8h] [bp-20h] BYREF

  v13[0] = a3;
  v3 = a1 + 168 * a2;
  v6 = PopPepComponentGetLatencyIdleState(v3 + 128);
  v7 = PopPepLockActivityLink(a1, (unsigned int *)(v3 + 128), 6, 1u, v13);
  *(_QWORD *)(v3 + 208) = a3;
  v8 = v7;
  if ( *(_DWORD *)(v3 + 252) != v6 )
  {
    *(_DWORD *)(v3 + 252) = v6;
    v9 = *(_DWORD *)(a1 + 72);
    v10 = *(_DWORD *)(v3 + 200);
    PopPepUpdateIdleState(a1, v3 + 128, 1);
    PopPepPromoteActivities(a1, v3 + 128, 2);
    PopPepRequestWork(v10 + v9, *(_DWORD *)(v3 + 200) + *(_DWORD *)(a1 + 72));
  }
  PopPepReleaseActivityLink(a1, (_DWORD *)(v3 + 128), v8, LOBYTE(v13[0]));
  return v12;
}
