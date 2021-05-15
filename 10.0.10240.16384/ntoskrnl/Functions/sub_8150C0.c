// sub_8150C0 
 
void __fastcall sub_8150C0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned __int16 a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int *a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26)
{
  int v26; // r4
  int *v27; // r5
  int v28; // r6
  int v29; // r0
  int v30; // r4
  int v31; // r1
  int v32; // r2
  __int16 *v33; // r1
  int v34; // r0

  v29 = IoGetDeviceAttachmentBaseRef(v26);
  v30 = v29;
  if ( v29 )
    v31 = *(_DWORD *)(*(_DWORD *)(v29 + 176) + 20);
  else
    v31 = 0;
  if ( v31 )
  {
    v32 = *(unsigned __int16 *)(v31 + 160) >> 1;
    a11 = (int)&a7 + 2;
    a12 = 0;
    a13 = 2;
    a14 = 0;
    HIWORD(a7) = v32;
    a15 = *(_DWORD *)(v31 + 164);
    a16 = 0;
    a17 = 2 * v32;
    a18 = 0;
    if ( v28 )
      v33 = L"passive";
    else
      v33 = L"active";
    RtlInitUnicodeString((unsigned int)&a9, (unsigned __int16 *)v33);
    v34 = *v27;
    a19 = &a7;
    a20 = 0;
    a21 = 2;
    a22 = 0;
    LOWORD(a7) = a9 >> 1;
    a23 = a10;
    a24 = 0;
    a25 = 2 * (a9 >> 1);
    a26 = 0;
    EtwWrite(v34, v27[1], (int)POP_ETW_EVENT_COOLING_MODE, 0);
  }
  if ( v30 )
    ObfDereferenceObject(v30);
  JUMPOUT(0x7A8AEE);
}
