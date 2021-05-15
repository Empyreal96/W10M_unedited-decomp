// AuthzBasepFreeSecurityAttributeValues 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall AuthzBasepFreeSecurityAttributeValues(int result, int a2)
{
  _DWORD *v2; // r5
  _DWORD *v3; // r4
  _DWORD *v4; // r0
  int v5; // r1 OVERLAPPED
  _DWORD *v6; // r2 OVERLAPPED
  _DWORD *v7; // r4
  _DWORD *v8; // r7
  int v9; // r3

  v2 = (_DWORD *)result;
  if ( !a2 )
  {
    v3 = (_DWORD *)(result + 44);
    while ( (_DWORD *)*v3 != v3 )
    {
      v4 = (_DWORD *)v2[11];
      if ( (v4[4] & 2) != 0 )
        return sub_51DD68();
      if ( (v4[4] & 1) != 0 )
      {
        *(_QWORD *)&v5 = *(_QWORD *)v4;
        if ( *(_DWORD **)(*v4 + 4) != v4 || (_DWORD *)*v6 != v4 )
          __fastfail(3u);
        *v6 = v5;
        *(_DWORD *)(v5 + 4) = v6;
        v4[4] &= 0xFFFFFFFE;
        --v2[9];
        if ( (v4[4] & 4) != 0 )
          JUMPOUT(0x51DD90);
      }
      result = ExFreePoolWithTag(v4, 0);
    }
  }
  v7 = (_DWORD *)v2[14];
  while ( v7 != v2 + 14 )
  {
    v8 = v7 - 2;
    v9 = v7[2];
    v7 = (_DWORD *)*v7;
    if ( (v9 & 1) == 0 )
    {
      AuthzBasepRemoveSecurityAttributeValueFromLists(v2, v8, 0);
      result = ExFreePoolWithTag(v8, 0);
    }
  }
  return result;
}
