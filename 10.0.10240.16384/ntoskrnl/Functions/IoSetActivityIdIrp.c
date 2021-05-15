// IoSetActivityIdIrp 
 
int __fastcall IoSetActivityIdIrp(int a1, _DWORD *a2, int a3)
{
  int v4; // r4
  _DWORD *v5; // r0

  v4 = 0;
  v5 = (_DWORD *)IopAllocateIrpExtension(a1, 0, a3);
  if ( !v5 )
    return -1073741670;
  if ( !a2 )
    return sub_552F68();
  v5[3] = *a2;
  v5[4] = a2[1];
  v5[5] = a2[2];
  v5[6] = a2[3];
  return v4;
}
