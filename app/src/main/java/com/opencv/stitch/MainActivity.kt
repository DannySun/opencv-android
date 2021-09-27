package com.opencv.stitch

import android.graphics.Bitmap
import android.graphics.BitmapFactory
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_main.*
import com.opencv.opencvlib.OpencvHandle;

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        sample_text.text = OpencvHandle.getInstance().test()
        image_view.setImageResource(R.drawable.robot)
        btn_start.setOnClickListener {
            var bitmap = BitmapFactory.decodeResource(resources, R.drawable.robot) ;
            OpencvHandle.getInstance().processBitmap(bitmap)
            image_view.setImageBitmap(bitmap);
        }
        init()
    }

    private fun init() {

    }
}
