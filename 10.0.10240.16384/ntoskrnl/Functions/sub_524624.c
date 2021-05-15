// sub_524624 
 
void sub_524624()
{
  int v0; // r4
  _DWORD *v1; // r6
  int v2; // r7
  int v3; // r5
  int v4; // r4

  v1[65] = v0;
  v3 = *(_DWORD *)(v2 + 72);
  v4 = v1[50];
  PopPepUpdateIdleState(v2, v1 + 32, 1);
  PopPepPromoteActivities(v2, (int)(v1 + 32), 2);
  PopPepRequestWork(v4 + v3, v1[50] + *(_DWORD *)(v2 + 72));
  JUMPOUT(0x45CFBC);
}
