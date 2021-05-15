// PiSwRemovePdoAssociation 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PiSwRemovePdoAssociation(int a1, int a2)
{
  int v2; // r4
  _DWORD *v3; // r0
  int v4; // r1 OVERLAPPED
  _DWORD *v5; // r2 OVERLAPPED

  v2 = 0;
  v3 = PiSwFindPdoAssociation(a1, a2, 0);
  if ( !v3 )
    return -1073741275;
  *(_QWORD *)&v4 = *(_QWORD *)v3;
  if ( *(_DWORD **)(*v3 + 4) != v3 || (_DWORD *)*v5 != v3 )
    __fastfail(3u);
  *v5 = v4;
  *(_DWORD *)(v4 + 4) = v5;
  PiSwPdoAssociationFree((unsigned int)v3);
  return v2;
}
