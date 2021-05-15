// sub_9684A8 
 
// local variable allocation has failed, the output may be wrong!
void sub_9684A8()
{
  int *v0; // r5
  int *v1; // r6
  int *v2; // r1 OVERLAPPED
  int **v3; // r2 OVERLAPPED
  int v4; // r2

  *(_QWORD *)&v2 = *(_QWORD *)v0;
  if ( *(int **)(*v0 + 4) == v0 && *v3 == v0 )
  {
    *v3 = v2;
    v2[1] = (int)v3;
    v4 = *v1;
    *v0 = *v1;
    v0[1] = (int)v1;
    if ( *(int **)(v4 + 4) == v1 )
    {
      *(_DWORD *)(v4 + 4) = v0;
      *v1 = (int)v0;
      JUMPOUT(0x94F700);
    }
    __fastfail(3u);
  }
  __fastfail(3u);
}
