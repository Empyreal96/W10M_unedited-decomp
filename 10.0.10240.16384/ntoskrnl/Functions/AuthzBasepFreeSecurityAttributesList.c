// AuthzBasepFreeSecurityAttributesList 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall AuthzBasepFreeSecurityAttributesList(int result)
{
  _DWORD *v1; // r6
  _DWORD *v2; // r4
  _DWORD *v3; // r5
  int v4; // r1 OVERLAPPED
  _DWORD *v5; // r2 OVERLAPPED

  v1 = (_DWORD *)result;
  v2 = (_DWORD *)(result + 4);
  while ( (_DWORD *)*v2 != v2 )
  {
    v3 = (_DWORD *)v1[1];
    if ( (v3[8] & 1) != 0 )
    {
      *(_QWORD *)&v4 = *(_QWORD *)v3;
      if ( *(_DWORD **)(*v3 + 4) != v3 || (_DWORD *)*v5 != v3 )
        sub_51DD64();
      *v5 = v4;
      *(_DWORD *)(v4 + 4) = v5;
      v3[8] &= 0xFFFFFFFE;
      --*v1;
    }
    AuthzBasepFreeSecurityAttributeValues(v3, 0);
    result = ExFreePoolWithTag(v3, 0);
  }
  return result;
}
