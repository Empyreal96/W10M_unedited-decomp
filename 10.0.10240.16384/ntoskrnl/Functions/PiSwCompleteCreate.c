// PiSwCompleteCreate 
 
int __fastcall PiSwCompleteCreate(int a1)
{
  int *v2; // r6
  int v3; // r2
  int v4; // r3
  int v5; // r0
  _DWORD *v6; // r2
  _DWORD *v7; // r5
  int result; // r0
  unsigned __int16 *v9; // r0
  int v10; // r3
  int v11; // r3
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r8
  int v15; // r4
  _DWORD *v16; // r5
  _DWORD *i; // r7
  _DWORD *v18; // t1
  int v19; // r8
  int v20; // r7
  int v21; // r10
  int v22; // r9
  int v23; // r0
  unsigned int v24; // r1
  int v25; // r3
  int *j; // r5
  int v27; // r3
  int **v28; // r0
  unsigned __int16 *v29; // r1
  int v30; // r0
  int v31; // r0
  int *v32; // r2
  int *v33; // [sp+0h] [bp-270h]
  int *v34; // [sp+8h] [bp-268h] BYREF
  int **v35; // [sp+Ch] [bp-264h]
  unsigned __int16 *v36; // [sp+10h] [bp-260h] BYREF
  int v37; // [sp+14h] [bp-25Ch]
  int v38; // [sp+18h] [bp-258h] BYREF
  int v39; // [sp+1Ch] [bp-254h]
  int v40; // [sp+20h] [bp-250h] BYREF
  int v41[2]; // [sp+28h] [bp-248h] BYREF
  __int16 v42; // [sp+30h] [bp-240h] BYREF
  int v43; // [sp+32h] [bp-23Eh]
  __int16 v44; // [sp+36h] [bp-23Ah]
  char v45[16]; // [sp+38h] [bp-238h] BYREF
  unsigned __int16 v46[276]; // [sp+48h] [bp-228h] BYREF

  v41[0] = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v35 = &v34;
  v34 = (int *)&v34;
  v2 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(__int16 *)(v3 + 0x134) - 1;
  *(_WORD *)(v3 + 308) = v4;
  v5 = ExAcquireResourceExclusiveLite((int)&PiSwLockObj, 1, v3, v4);
  v6 = *(_DWORD **)(a1 + 40);
  v7 = (_DWORD *)*v6;
  if ( !*v6 )
    return sub_7E0A68(v5);
  v6[1] &= 0xFFFFFFF9;
  if ( v7[12] )
    goto LABEL_50;
  v9 = (unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 20);
  v10 = v7[11];
  v41[0] = (int)v9;
  if ( !v10 )
  {
    if ( PnpAllocatePWSTR(*((unsigned __int16 **)v9 + 1), (*v9 >> 1) + 1, 1466986064, (int *)&v36) < 0 )
      goto LABEL_50;
    RtlInitUnicodeString((unsigned int)(v7 + 10), v36);
  }
  v11 = v7[19];
  if ( !v11 )
    goto LABEL_15;
  __dmb(0xBu);
  v12 = (unsigned int *)(v11 + 56);
  do
    v13 = __ldrex(v12);
  while ( __strex(0, v12) );
  __dmb(0xBu);
  if ( !v13 )
    goto LABEL_15;
  v2 = (int *)v7[19];
  v7[19] = 0;
  if ( !v2 )
    goto LABEL_15;
  v14 = v2[24];
  if ( RtlStringCbCopyW(v2[3], *(_DWORD *)(v14 + 8)) < 0 )
LABEL_50:
    JUMPOUT(0x7E0A6A);
  if ( RtlStringCbLengthW(v2[3], *(_DWORD *)(v14 + 8), &v38) < 0 )
    goto LABEL_51;
  v39 = v38;
LABEL_15:
  v33 = &v40;
  v15 = PnpCopyDevPropertyArray(v7[23], v7[22]);
  if ( v15 < 0 )
LABEL_51:
    JUMPOUT(0x7E0A6E);
  v18 = (_DWORD *)v7[25];
  v16 = v7 + 25;
  for ( i = v18; i != v16; i = (_DWORD *)*i )
  {
    v15 = PiSwInterfaceCreate(i[2], i[3], i[4], &v36, v33);
    if ( v15 < 0 )
      goto LABEL_51;
    v28 = v35;
    v29 = v36;
    *(_DWORD *)v36 = &v34;
    *((_DWORD *)v29 + 1) = v28;
    if ( *v28 != (int *)&v34 )
      __fastfail(3u);
    *v28 = (int *)v29;
    v35 = (int **)v29;
  }
  v19 = a1;
  ObfReferenceObject(a1);
  v21 = v39;
  v20 = v40;
  v22 = v37;
  v23 = ExReleaseResourceLite((int)&PiSwLockObj);
  v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v25 = (__int16)(*(_WORD *)(v24 + 0x134) + 1);
  *(_WORD *)(v24 + 308) = v25;
  if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
    v23 = KiCheckForKernelApcDelivery(v23);
  if ( v20 )
  {
    v23 = PiSwPropertySet(*(unsigned __int16 **)(v41[0] + 4), 1, v20, v22);
    v15 = v23;
  }
  for ( j = v34; j != (int *)&v34; j = (int *)*j )
  {
    v30 = CmGetDeviceInterfaceClassGuid(v23, (unsigned __int16 *)j[2], v45);
    v15 = v30;
    if ( v30 < 0 )
      break;
    v31 = CmGetDeviceInterfaceReferenceString(v30, (unsigned __int16 *)j[2], v46, 0x104u, (unsigned int *)&v36);
    v15 = v31;
    if ( v31 == -1073741772 )
    {
      v32 = 0;
    }
    else
    {
      if ( v31 < 0 )
        break;
      RtlInitUnicodeString((unsigned int)v41, v46);
      v32 = v41;
    }
    v15 = IoRegisterDeviceInterface(v19, (int)v45, (int)v32, &v42);
    if ( v15 < 0 )
      break;
    v23 = PiSwPropertySet((unsigned __int16 *)j[2], 3, j[3], j[4]);
    v15 = v23;
    if ( v23 < 0 )
      break;
  }
  if ( v19 )
    ObfDereferenceObject(v19);
  if ( v20 )
    PnpFreeDevPropertyArray(v22, v20);
  PiSwFreeInterfaceList(&v34);
  result = RtlFreeAnsiString(&v42);
  if ( v2 )
  {
    if ( v15 < 0 )
      v27 = 0;
    else
      v27 = v21 + 2;
    v2[6] = v15;
    v2[7] = v27;
    result = IofCompleteRequest((int)v2, 0);
  }
  return result;
}
