// sub_7DE748 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_7DE748(int a1, int a2, int a3, _QWORD *a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, __int16 a15, unsigned __int16 *a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, __int16 *a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36)
{
  int v36; // r7 OVERLAPPED
  int v37; // r8 OVERLAPPED
  int v38; // r4
  int v39; // r3

  *(_QWORD *)&v36 = *a4;
  if ( *a4 )
  {
    if ( EtwEventEnabled(v36, v37, (int)KMPnPEvt_DeviceEject_Start) )
    {
      v38 = *a16;
      a15 = *a16 >> 1;
      a29 = &a15;
      a30 = 0;
      a31 = 2;
      a32 = 0;
      v39 = *((_DWORD *)a16 + 1);
      a35 = v38;
      a33 = v39;
      a34 = 0;
      a36 = 0;
      EtwWrite(v36, v37, (int)KMPnPEvt_DeviceEject_Start, 0);
    }
  }
  JUMPOUT(0x774AB0);
}
