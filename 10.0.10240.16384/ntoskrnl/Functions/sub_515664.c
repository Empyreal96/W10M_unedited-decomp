// sub_515664 
 
// local variable allocation has failed, the output may be wrong!
void sub_515664()
{
  int v0; // r4
  _QWORD *v1; // r5
  int v2; // r6
  int *v3; // r2 OVERLAPPED
  int v4; // r1 OVERLAPPED

  ++*(_DWORD *)(v0 + 4);
  v3 = (int *)(v0 + 8 * (v2 + 2));
  v4 = *v3;
  *v1 = *(_QWORD *)&v4;
  if ( *(int **)(v4 + 4) != v3 )
    __fastfail(3u);
  *(_DWORD *)(v4 + 4) = v1;
  *v3 = (int)v1;
  JUMPOUT(0x433A44);
}
