// _PnpContainerRaiseDevicesChangedEvent 
 
int __fastcall PnpContainerRaiseDevicesChangedEvent(int result, int a2)
{
  void (__fastcall *v2)(int, int, int, int, int *); // r5
  int v4; // r4
  int (**v5)[5]; // r7
  int v6; // r8
  int v7; // t1
  int v8; // [sp+4h] [bp-2Ch]
  int v9; // [sp+8h] [bp-28h] BYREF
  int v10; // [sp+Ch] [bp-24h]
  int v11; // [sp+10h] [bp-20h]

  v2 = *(void (__fastcall **)(int, int, int, int, int *))(result + 156);
  v4 = result;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  if ( v2 )
  {
    v9 = 0;
    v2(result, a2, 5, 5, &v9);
    v5 = off_40BB8C;
    v9 = 0;
    v10 = 0;
    v6 = 3;
    do
    {
      v7 = (int)*v5++;
      v11 = v7;
      result = ((int (__fastcall *)(int, int, int, int, int *, int))v2)(v4, a2, 5, 4, &v9, v8);
      --v6;
    }
    while ( v6 );
  }
  return result;
}
