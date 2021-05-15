// IoCancelThreadIo 
 
void IoCancelThreadIo()
{
  int v0; // r3
  _DWORD **v1; // r4
  int v2; // r0
  _DWORD *v3; // r5
  int v4; // r6
  int v5; // r0

  v0 = __mrc(15, 0, 13, 0, 3);
  v1 = (_DWORD **)((v0 & 0xFFFFFFC0) + 908);
  if ( *(_DWORD ***)((v0 & 0xFFFFFFC0) + 0x38C) != v1 )
  {
    v2 = KfRaiseIrql(1);
    v3 = *v1;
    v4 = v2;
    while ( v1 != v3 )
    {
      IoCancelIrp((int)(v3 - 4));
      v3 = (_DWORD *)*v3;
    }
    KfLowerIrql(v4);
    v5 = KfRaiseIrql(1);
    if ( *v1 == v1 )
      KfLowerIrql(v5);
    else
      sub_7F33AC(v5);
  }
}
