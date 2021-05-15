// HalExamineMBR 
 
int __fastcall HalExamineMBR(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  unsigned int v4; // r5
  int v7; // r1
  int result; // r0
  int v9; // r4
  int v10; // r0
  int v11; // r0
  _DWORD v12[2]; // [sp+10h] [bp-38h] BYREF
  int v13; // [sp+18h] [bp-30h] BYREF
  char v14[4]; // [sp+20h] [bp-28h] BYREF
  int v15; // [sp+24h] [bp-24h]
  int v16[8]; // [sp+28h] [bp-20h] BYREF

  *a4 = 0;
  v4 = a2;
  if ( a2 < 0x200 )
    v4 = 512;
  v7 = 4096;
  v12[0] = 0;
  v12[1] = 0;
  if ( v4 >= 0x1000 )
    v7 = v4;
  result = ExAllocatePoolWithTag(516, v7, 1651798854);
  v9 = result;
  if ( result )
  {
    v16[1] = (int)v16;
    v16[0] = (int)v16;
    v14[0] = 0;
    v14[1] = 0;
    v14[2] = 4;
    v15 = 0;
    v10 = ((int (__fastcall *)(int, int, int, unsigned int, _DWORD *, char *, int *))IoBuildSynchronousFsdRequest)(
            3,
            a1,
            result,
            v4,
            v12,
            v14,
            &v13);
    if ( !v10 )
      goto LABEL_13;
    *(_BYTE *)(*(_DWORD *)(v10 + 96) - 38) |= 2u;
    v11 = IofCallDriver(a1, v10);
    if ( v11 == 259 )
    {
      KeWaitForSingleObject(v14, 0, 0);
      v11 = v13;
    }
    if ( v11 >= 0 && *(unsigned __int16 *)(v9 + 510) == 43605 && *(unsigned __int8 *)(v9 + 450) == a3 )
      result = sub_51AFD4();
    else
LABEL_13:
      result = ExFreePoolWithTag(v9, 0);
  }
  return result;
}
