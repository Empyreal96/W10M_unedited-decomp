// sub_819EDC 
 
// local variable allocation has failed, the output may be wrong!
void sub_819EDC()
{
  unsigned int *v0; // r4
  unsigned int *v1; // r1 OVERLAPPED
  unsigned int **v2; // r2 OVERLAPPED

  *(_QWORD *)&v1 = *(_QWORD *)v0;
  if ( *(unsigned int **)(*v0 + 4) == v0 && *v2 == v0 )
  {
    *v2 = v1;
    v1[1] = (unsigned int)v2;
    ExFreePoolWithTag(v0[3]);
    ExFreePoolWithTag((unsigned int)v0);
    JUMPOUT(0x7B66F4);
  }
  __fastfail(3u);
}
