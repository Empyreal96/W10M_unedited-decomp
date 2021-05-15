// sub_7EE9B4 
 
// local variable allocation has failed, the output may be wrong!
void sub_7EE9B4()
{
  int v0; // r0
  _DWORD *v1; // r4
  int v2; // r1 OVERLAPPED
  _DWORD *v3; // r2 OVERLAPPED

  *(_QWORD *)&v2 = *(_QWORD *)v1;
  if ( *(_DWORD **)(*v1 + 4) != v1 || (_DWORD *)*v3 != v1 )
    __fastfail(3u);
  *v3 = v2;
  *(_DWORD *)(v2 + 4) = v3;
  ObfDereferenceObject(v1[7]);
  if ( v1[2] == 3 )
  {
    v0 = v1[12];
    if ( v0 )
    {
      ObfDereferenceObject(v0);
      v1[12] = 0;
    }
  }
  if ( v1[4] )
  {
    ZwClose();
    v1[4] = 0;
  }
  ExDeleteResourceLite((_DWORD *)v1[10]);
  ExFreePoolWithTag(v1[10]);
  ExFreePoolWithTag((unsigned int)v1);
  JUMPOUT(0x780874);
}
