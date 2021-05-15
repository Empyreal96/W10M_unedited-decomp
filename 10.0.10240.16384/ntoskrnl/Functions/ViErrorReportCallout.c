// ViErrorReportCallout 
 
_DWORD *__fastcall ViErrorReportCallout(_DWORD *result)
{
  int v1; // r5
  unsigned int v2; // r6
  unsigned int v3; // r4
  unsigned int v4; // r3
  unsigned int v5; // r2
  unsigned __int64 v6; // r0
  int v7; // r5
  unsigned int v8; // r6
  unsigned int v9; // r4
  unsigned int v10; // r7
  unsigned __int64 v11; // kr28_8
  __int64 v12; // kr30_8
  unsigned int *v13; // r6
  int v14; // r4
  unsigned int v15; // r5
  unsigned int v16; // r6
  int v17; // r6
  unsigned int v18; // r7
  unsigned int v19; // r5
  _BYTE v20[12]; // [sp+0h] [bp-98h]
  char v21[136]; // [sp+10h] [bp-88h] BYREF

  switch ( *result )
  {
    case 1:
      v1 = result[2];
      v2 = result[1];
      v3 = result[3];
      ViErrorDisplayDescription(v2);
      *(_DWORD *)v20 = v3;
      if ( RtlStringCbPrintfA((int)v21, 0x30u, (int)"CulpritAddress = %p, Irp = %p.\n", v1) < 0 )
        goto LABEL_4;
      goto LABEL_3;
    case 2:
      v7 = result[2];
      v8 = result[1];
      v9 = result[4];
      v10 = *(_DWORD *)result[3];
      ViErrorDisplayDescription(v8);
      *(_DWORD *)&v20[4] = v9;
      *(_DWORD *)v20 = v10;
      if ( RtlStringCbPrintfA((int)v21, 0x4Bu, (int)"CulpritAddress = %p, Irp = %p, DeviceObject = %p.\n", v7) >= 0 )
        goto LABEL_6;
      goto LABEL_7;
    case 3:
      v7 = result[2];
      v8 = result[1];
      v9 = result[4];
      v10 = *(_DWORD *)result[3];
      ViErrorDisplayDescription(v8);
      *(_DWORD *)&v20[4] = v9;
      *(_DWORD *)v20 = v10;
      if ( RtlStringCbPrintfA((int)v21, 0x47u, (int)"CulpritAddress = %p, Irp = %p, Status = 0x%x.\n", v7) >= 0 )
LABEL_6:
        VfUtilDbgPrint((int)v21);
LABEL_7:
      v5 = v10;
      v6 = __PAIR64__(v7, v8);
      goto LABEL_31;
    case 4:
      v11 = *(_QWORD *)(result + 1);
      v12 = *((_QWORD *)result + 2);
      v13 = (unsigned int *)result[3];
      ViErrorDisplayDescription(result[1]);
      *(_DWORD *)v20 = *v13;
      *(_QWORD *)&v20[4] = v12;
      if ( RtlStringCbPrintfA(
             (int)v21,
             0x6Cu,
             (int)"CulpritAddress = %p, Irp = %p, ExpectedStatus = 0x%x, ActualStatus = 0x%x.\n",
             SHIDWORD(v11)) >= 0 )
        VfUtilDbgPrint((int)v21);
      v5 = *v13;
      v4 = v12;
      v6 = v11;
      goto LABEL_32;
    case 5:
      v14 = result[2];
      v15 = result[1];
      v16 = *(_DWORD *)result[3];
      ViErrorDisplayDescription(v15);
      *(_DWORD *)v20 = v16;
      if ( RtlStringCbPrintfA((int)v21, 0x30u, (int)"CulpritAddress = %p, Irp = %p.\n", v14) >= 0 )
        VfUtilDbgPrint((int)v21);
      v4 = 0;
      v5 = v16;
      goto LABEL_16;
    case 6:
      v17 = result[2];
      v18 = result[1];
      v9 = result[4];
      v19 = result[3];
      ViErrorDisplayDescription(v18);
      *(_QWORD *)v20 = __PAIR64__(v9, v19);
      if ( RtlStringCbPrintfA((int)v21, 0x47u, (int)"CulpritAddress = %p, Irp = %p, Status = 0x%x.\n", v17) >= 0 )
        goto LABEL_29;
      goto LABEL_30;
    case 7:
      v17 = result[2];
      v18 = result[1];
      v9 = result[4];
      v19 = result[3];
      ViErrorDisplayDescription(v18);
      *(_QWORD *)v20 = __PAIR64__(v9, v19);
      if ( RtlStringCbPrintfA(
             (int)v21,
             0x56u,
             (int)"CulpritAddress = %p, DeviceObject1 = %p, DeviceObject2 = %p.\n",
             v17) >= 0 )
        goto LABEL_29;
      goto LABEL_30;
    case 8:
      v1 = result[2];
      v2 = result[1];
      v3 = result[3];
      ViErrorDisplayDescription(v2);
      *(_DWORD *)v20 = v3;
      if ( RtlStringCbPrintfA((int)v21, 0x39u, (int)"CulpritAddress = %p, DeviceObject = %p.\n", v1) >= 0 )
LABEL_3:
        VfUtilDbgPrint((int)v21);
LABEL_4:
      v4 = 0;
      v5 = v3;
      v6 = __PAIR64__(v1, v2);
      goto LABEL_32;
    case 9:
      v14 = result[2];
      v15 = result[1];
      ViErrorDisplayDescription(v15);
      if ( RtlStringCbPrintfA((int)v21, 0x1Eu, (int)"CulpritAddress = %p.\n", v14) >= 0 )
        VfUtilDbgPrint((int)v21);
      v4 = 0;
      v5 = 0;
LABEL_16:
      v6 = __PAIR64__(v14, v15);
      goto LABEL_32;
    case 0xA:
      v17 = result[2];
      v18 = result[1];
      v9 = result[4];
      v19 = result[3];
      ViErrorDisplayDescription(v18);
      *(_QWORD *)v20 = __PAIR64__(v9, v19);
      if ( RtlStringCbPrintfA((int)v21, 0x4Bu, (int)"CulpritAddress = %p, Irp = %p, DeviceObject = %p.\n", v17) >= 0 )
        goto LABEL_29;
      goto LABEL_30;
    case 0xB:
      v17 = result[2];
      v18 = result[1];
      v9 = *((unsigned __int8 *)result + 16);
      v19 = result[3];
      ViErrorDisplayDescription(v18);
      *(_DWORD *)&v20[4] = v9;
      *(_DWORD *)v20 = v19;
      if ( RtlStringCbPrintfA((int)v21, 0x43u, (int)"CulpritAddress = %p, Irp = %p, IRQL = %u.\n", v17) >= 0 )
LABEL_29:
        VfUtilDbgPrint((int)v21);
LABEL_30:
      v6 = __PAIR64__(v17, v18);
      v5 = v19;
LABEL_31:
      v4 = v9;
LABEL_32:
      result = (_DWORD *)ViErrorFinishReport(
                           v6,
                           HIDWORD(v6),
                           v5,
                           v4,
                           *(_DWORD *)v20,
                           *(_DWORD *)&v20[4],
                           *(_DWORD *)&v20[8]);
      break;
    default:
      return result;
  }
  return result;
}
