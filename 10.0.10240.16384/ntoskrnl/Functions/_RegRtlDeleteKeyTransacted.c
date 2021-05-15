// _RegRtlDeleteKeyTransacted 
 
int __fastcall RegRtlDeleteKeyTransacted(int a1, unsigned __int16 *a2, int a3)
{
  int v3; // r4
  int v5; // [sp+8h] [bp-8h] BYREF

  v5 = 0;
  if ( !a2 || (v3 = RegRtlOpenKeyTransacted(a1, a2, 0, 0x10000, (int)&v5, a3), v3 >= 0) )
    v3 = ZwDeleteKey();
  if ( v5 )
    ZwClose();
  return v3;
}
