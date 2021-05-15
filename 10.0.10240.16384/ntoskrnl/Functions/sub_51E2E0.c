// sub_51E2E0 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_51E2E0(_DWORD *a1)
{
  int v1; // r4
  unsigned int v2; // r7 OVERLAPPED
  unsigned int v3; // r8 OVERLAPPED

  *(_QWORD *)&v2 = *(_QWORD *)(v1 + 32);
  do
  {
    if ( *((_QWORD *)a1 + 2) > __PAIR64__(v3, v2)
      || (a1[10] != *(_DWORD *)(v1 + 24) || a1[11] != *(_DWORD *)(v1 + 28) || a1[9] != *(_DWORD *)(v1 + 20))
      && (*(_QWORD *)(v1 + 8) || *((_QWORD *)a1 + 3)) )
    {
      break;
    }
    a1 = RtlRealSuccessor(a1);
  }
  while ( a1 );
  JUMPOUT(0x44CB3E);
}
