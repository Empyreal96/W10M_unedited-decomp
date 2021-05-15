// sub_7DE998 
 
void __fastcall sub_7DE998(int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned __int16 *a8, unsigned __int16 *a9, int a10, int a11, int a12, unsigned __int16 a13, int a14, unsigned __int16 a15, int a16, int *a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int *a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36)
{
  _DWORD *v36; // r5
  unsigned __int16 *v37; // r6
  _DWORD *v38; // r8
  int v39; // r10
  int v40; // r7
  unsigned __int16 *v41; // r4
  int v42; // r0
  int v43; // r3
  int v44; // r3
  int v45; // r2
  int v46; // r3
  int v47; // r2
  int v48; // r3
  __int64 v49; // kr00_8
  _DWORD *v50; // r6
  int v51; // r9
  int v52; // r3

  while ( 1 )
  {
    v39 = 0;
    if ( PsLookupProcessByProcessId(v36[2], &a10) >= 0 )
    {
      v40 = a10;
      if ( PsGetAllocatedFullProcessImageName(a10, &a8) >= 0 )
      {
        v41 = a8;
        if ( !*a8 )
        {
          v39 = 1;
          ExFreePoolWithTag((unsigned int)a8);
          v41 = &a15;
          a8 = &a15;
          v42 = PsGetProcessImageFileName(v40);
          RtlInitAnsiString((unsigned int)&a13, v42);
          RtlAnsiStringToUnicodeString(&a15, &a13, 1, v43);
        }
      }
      else
      {
        v41 = 0;
        a8 = 0;
      }
      a11 = *(_DWORD *)(v40 + 176);
      a17 = &a11;
      a18 = 0;
      a19 = 4;
      a20 = 0;
      if ( v41 )
        v44 = *v41 >> 1;
      else
        v44 = 0;
      v45 = v44;
      HIWORD(a7) = v44;
      a21 = (int)&a7 + 2;
      a22 = 0;
      a23 = 2;
      a24 = 0;
      if ( v41 )
        v46 = *((_DWORD *)v41 + 1);
      else
        v46 = 0;
      a25 = v46;
      a26 = 0;
      a27 = 2 * v45;
      a28 = 0;
      v47 = *v37 >> 1;
      a29 = &a7;
      a30 = 0;
      a31 = 2;
      a32 = 0;
      v48 = *((_DWORD *)v37 + 1);
      v49 = PnpEtwHandle;
      LOWORD(a7) = v47;
      a33 = v48;
      a34 = 0;
      a35 = 2 * v47;
      a36 = 0;
      if ( PnpEtwHandle && EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DeviceEject_Pend) )
        EtwWrite(v49, SHIDWORD(v49), (int)KMPnPEvt_DeviceEject_Pend, 0);
      v50 = (_DWORD *)(*v36 - 4);
      if ( v36 != (_DWORD *)*v36 )
      {
        v51 = (int)a9;
        do
        {
          if ( *v50 )
            v52 = *(_DWORD *)(*(_DWORD *)(*v50 + 176) + 20);
          else
            v52 = 0;
          PnpTraceDeviceRemoveProcessVeto(v51, v52 + 20, v41);
          v50 = (_DWORD *)(v50[1] - 4);
        }
        while ( v36 != v50 + 1 );
      }
      if ( v39 )
      {
        RtlFreeAnsiString(v41);
      }
      else if ( v41 )
      {
        ExFreePoolWithTag((unsigned int)v41);
      }
      ObfDereferenceObjectWithTag(v40);
      v37 = a9;
    }
    v36 = (_DWORD *)(v36[3] - 12);
    if ( v38 == v36 + 3 )
      JUMPOUT(0x774C58);
  }
}
